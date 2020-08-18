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
t = [0] * 70
t[0] = 0
t[1] = 1
for i in range(2, 60): t[i] = t[i-1] + t[i-2] + 1

# Compute depths in input tree
height = [0] * (n+2)
def height_dfs(u):
    if l[u]!=-1: height_dfs(l[u])
    if r[u]!=-1: height_dfs(r[u])
    height[u] = max(height[l[u]] + 1, height[r[u]] + 1)
height_dfs(root)

# The state of what we've taken so far.
take = [False] * n
h = [0] * n

def dfs(u):
    global k, h, l, r, take

    # This node was already assumed.
    if h[u] > 0:
        take[u] = True
        hl, hr = h[u]-1, h[u]-2
        if height[l[u]] < hl: hl, hr = hr, hl
        if l[u] != -1:
            h[l[u]] = hl
            dfs(l[u])
        if r[u] != -1:
            h[r[u]] = max(hr, h[l[u]]-1)
            dfs(r[u])
        return

    # Number of nodes needed to add u.
    a = 1

    pp = p[u]
    hh = 2
    while pp != -1 and h[pp] < hh:
        if pp > u: a += t[hh-2] - t[h[pp]-2]

        pp = p[pp]
        hh += 1

    if a > k: return

    # Add u
    take[u] = True
    k -= a
    pp = u
    hh = 1
    while pp != -1 and h[pp] < hh:
        h[pp] = hh

        pp = p[pp]
        hh += 1

    if l[u] != -1:
        dfs(l[u])
    if r[u] != -1:
        h[r[u]] = h[u]-2
        dfs(r[u])

dfs(root)

print(*[int(x) for x in take], sep='')
