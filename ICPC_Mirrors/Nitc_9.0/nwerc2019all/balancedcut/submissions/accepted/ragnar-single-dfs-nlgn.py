#!/usr/bin/env python3
from math import log

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

# Partial sums of t
ts = [0] * 60
for i in range(1, 60): ts[i] = ts[i-1] + t[i]

# Compute depths
height = [0] * n
def height_dfs(u):
    height[u] = 1
    if l[u]!=-1: height[u] = max(height[u], height_dfs(l[u])+1)
    if r[u]!=-1: height[u] = max(height[u], height_dfs(r[u])+1)
    return height[u]
height_dfs(root)


# Heights of all parents of the current vertex
parent_heights = [-2]

take = [False] * n

right_branch_height = []
def dfs(u, forced_h = 0):
    global k, right_branch_height
    #if k == 0: return

    # current height of new node
    parent_heights.append(forced_h)

    assert len(parent_heights) <= height[root] + 1
    assert len(right_branch_height) <= height[root] + 1

    #print()
    #print("DFS: ", u, forced_h, parent_heights)

    if forced_h > 0:
        #print("Forced node: ", u)
        # already accounted for
        take[u] = True
        lh = forced_h - 1
        rh = forced_h - 2
        # If the left tree isn't deep enough, swap left and right
        if forced_h > 1 and (l[u] == -1 or height[l[u]] < lh):
            #print('SWAP: ', lh, rh, ' for left height ', height[l[u]])
            lh, rh = rh, lh

        if l[u] != -1: dfs(l[u], lh)
        rh = max(rh, max(parent_heights[-1]-2, 0))
        if r[u] != -1:
            right_branch_height.append(parent_heights[-1])
            dfs(r[u], rh)
            right_branch_height.pop()

        parent_heights.pop()
        return


    # find the length of the delta=1 path that's 'tense'
    tense = 0
    for i in range(len(parent_heights)-1, 0, -1):
        if parent_heights[i-1] == 1 + parent_heights[i]:
            tense += 1
        else: break

    # account for the extra nodes needed
    count = t[tense+1] - t[tense]
    #print("tense: ", tense, " required count: ", count, " remaining k: " , k)
    for h in reversed(right_branch_height):
        if tense >= h and h >= 2:
    #if right_branch_height >= 2 and tense >= right_branch_height:
            count -= t[h-1] - t[h-2]
        #right_branch_neight = 0
    #print("right_branch_height: ", right_branch_height, "new count: ", count)
    if count > k:
        parent_heights.pop()
        return

    take[u] = True
    k -= count
    parent_heights[-1] += 1
    for i in range(len(parent_heights)-2, -1, -1):
        if parent_heights[i] == parent_heights[i+1]:
            parent_heights[i] += 1
        else: break

    if l[u] != -1:
        # If the left subtree isn't deep enough for the current height, reserve
        # some extra nodes for the right subtree.
        #reserved = 0
        ##print("NEEDED HEIGHT: ", parent_heights[-2]-1, " LEFT HEIGHT: ",
                #height[l[u]])
        #if height[l[u]] < h:
            #reserved = t[parent_heights[-1]-1] - t[parent_heights[-1]-2]
            ##print("RESERVE NODES FOR DEEPER RIGHT SUBTREE: ", reserved)
#
        #k -= reserved
        dfs(l[u])
        #k += reserved
    if r[u] != -1:
        # Add space for the nodes we already counted before.
        #add = 0
        #if parent_heights[-1] > 2: add = t[parent_heights[-1]-2]
        #k += add
        ##print(u, "Right dfs: ", parent_heights, " Add extra room: ", add)
        right_branch_height.append(parent_heights[-1])
        #print("Setting right_branch_height to: ", right_branch_height)
        #print(u, " Parent height before right DFS: ", parent_heights)
        dfs(r[u], max(parent_heights[-1]-2, 0))
        right_branch_height.pop()

    #print(u, "New parent heights (before pop): ", parent_heights)
    parent_heights.pop()

dfs(root)

print(*[int(x) for x in take], sep='')
