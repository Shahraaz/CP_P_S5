#!/usr/bin/env python3
from math import log
from sys import stderr

n, k = [int(x) for x in input().split()]
p = [-1] * n # parent
l = [-1] * n # left child
r = [-1] * n # right child
root = -1
for i in range(n):
    f = int(input())-1
    if f == -2:
        f = -1
        root = i
        continue
    p[i] = f
    assert f != i
    if i > f:
        assert r[f] == -1
        r[f] = i
    if i < f:
        assert l[f] == -1
        l[f] = i
assert root != -1

# number of nodes in minimal tree of height h
t = [0] * 60
t[0] = 0
t[1] = 1
for i in range(2, 60): t[i] = t[i-1] + t[i-2] + 1
t.append(0)

# Compute heights and depths
height = [0] * n
depth = [1] * n
def height_dfs(u):
    height[u] = 1
    if l[u]!=-1:
        depth[l[u]] = depth[u] + 1
        height[u] = max(height[u], height_dfs(l[u])+1)
    if r[u]!=-1:
        depth[r[u]] = depth[u] + 1
        height[u] = max(height[u], height_dfs(r[u])+1)
    return height[u]
height_dfs(root)


# Heights of all parents of the current vertex

take = [False] * n

# Heights at which we branched to the right.
# We don't have to count nodes left of these.

# Don't add nodes deeper than this.
maxd = 1000

forced_lengths = [[0,0]]

# Returns the height of the generated tree.
def dfs(u, h = 0, consecutive = False):
    global k, maxd, forced_lengths

    if not h and depth[u] > maxd: return 0

    # Add this node to path of delta=1 nodes or create a new path.
    if consecutive:
        forced_lengths[-1][0] += 1
    else:
        forced_lengths.append([1, 0])

    def unwind():
        forced_lengths[-1][0] -= 1
        if forced_lengths[-1][0] == 0:
            forced_lengths.pop()

    if h > 0:
        # already accounted for
        take[u] = True
        lh = h - 1
        rh = h - 2
        # If the left tree isn't deep enough, swap left and right
        if h > 1 and (l[u] == -1 or height[l[u]] < lh):
            lh, rh = rh, lh

        if l[u] != -1: h = max(h, 1+dfs(l[u], lh, consecutive=lh==h-1))
        rh = max(rh, max(h-2,0))
        if r[u] != -1:
            added = t[h-1] - t[h-2]
            forced_lengths[-1][1] += added
            h = max(h, 1+dfs(r[u], rh, consecutive=rh==h-1))
            forced_lengths[-1][1] -= added

        unwind()
        return h

    # find the length of the delta=1 path that's 'tense'
    count = t[forced_lengths[-1][0]] - t[forced_lengths[-1][0]-1] - forced_lengths[-1][1]

    # POSSIBLE TO ADD THIS NODE?
    if count <= k:
        # Merge Forced Lengths
        if len(forced_lengths) > 1:
            forced_lengths[-2][0] += forced_lengths[-1][0]
            forced_lengths[-2][1] += forced_lengths[-1][1]
            forced_lengths.pop()

        take[u] = True
        k -= count
        h = 1
        if l[u] != -1:
            h = max(h, 1+dfs(l[u], consecutive=True))
        if r[u] != -1:
            added = t[h-1] - t[h-2]
            forced_lengths[-1][1] += added
            h = max(h, 1+dfs(r[u], max(h-2, 0), consecutive=h==1))
            forced_lengths[-1][1] -= added
    else:
        maxd = depth[u] - 1

    unwind()
    return h

dfs(root)

print(*[int(x) for x in take], sep='')
