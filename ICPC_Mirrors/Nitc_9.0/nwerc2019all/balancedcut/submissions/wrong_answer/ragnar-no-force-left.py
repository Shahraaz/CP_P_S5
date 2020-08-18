#!/usr/bin/env python3
from math import log

# Difference from ragnar-maybe-too-slow:
# If at some point we can not add a node at level d, because it would imply too
# many dependencies, we never again try to add a node at levels >= d from that
# moment onward.

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

# For each node, find the first node at each level underneath it.
depth = int(2+1.5 * log(n+2)/log(2))
first = [[-1] * depth for _ in range(n)]
for i in range(n):
    first[i][0] = i
    d = 1
    u = p[i]
    while u != -1:
        if first[u][d] == -1:
            first[u][d] = i
        d += 1
        u = p[u]

forced = [[] for _ in range(n)]
for i in range(n):
    if p[i] == -1: continue
    d = 1
    u = p[i]
    forced[i].append(u)
    while u != -1:
        # Maybe remove the u>i condition here? (Would make it a bit slower
        # though.)
        if u > i and d > 1:
            forced[i].append(first[r[u]][d-2])
        u = p[u]
        d += 1

take = [False] * n
s = 0

added = []

# Add the dependencies for u and then u itself
def visit(u):
    global s
    if take[u]: return True
    if s == k: return False

    for v in forced[u]:
        if v == -1: continue
        if not visit(v):
            return False

    if s == k: return False
    take[u] = True
    if p[u] != -1: assert take[p[u]]
    added.append(u)
    s += 1
    return True

# Walk the tree in pre-order.
maxd = 1000000
def dfs(u, d):
    global added, s, maxd
    if s == k: return
    if d > maxd: return
    added = []
    if not visit(u):
        if len(added) > 0: assert added[-1] != u
        for x in added:
            take[x] = False
            s -= 1
        maxd = d-1
        return

    assert take[u]

    if l[u] != -1: dfs(l[u], d+1)
    if r[u] != -1: dfs(r[u], d+1)

dfs(root, 0)

print(*[int(x) for x in take], sep='')
