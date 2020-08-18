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
#print('p', *p)
#print('l', *l)
#print('r', *r)

# For each node, record the nodes for which it is the lowest node at a give level.
depth = int(2+1.5 * log(n+2)/log(2))
first = [[-1] * depth for _ in range(n)]
firstfor = [[] for _ in range(n)]
for i in range(n):
    first[i][0] = i
    d = 1
    u = p[i]
    while u != -1:
        #print(i, u, d, depth, first[u][d])
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
        # Maybe remove the u>i condition here?
        if d > 1:
            #print(i, u, d, first[u])
            forced[i].append(first[r[u]][d-2])
        u = p[u]
        d += 1
    #print(i, forced[i])

take = [False] * n
s = 0

added = []

# Add the dependencies for u and then u itself
def visit(u):
    #print('visit', u, 'parent', p[u], ' forced', forced[u])
    global s
    if take[u]: return True
    if s == k: return False
    #if p[u] != -1:
        #assert take[p[u]]

    for v in forced[u]:
        if v == -1: continue
        if take[v]: continue
        if v < u: continue # if we're on the right, no need to fix things
        if not visit(v):
                return False

    if s == k: return False
    #print('Take', u)
    take[u] = True
    added.append(u)
    s += 1
    return True

# Walk the tree in pre-order.
def dfs(u):
    global added, s
    if s == k: return
    #print('dfs', u, l[u], r[u])
    added = []
    if not visit(u):
        #print('reset visit', u)
        if len(added) > 0: assert added[-1] != u
        for x in added:
            take[x] = False
            s -= 1
        return

    assert take[u]

    if l[u] != -1: dfs(l[u])
    if r[u] != -1: dfs(r[u])

dfs(root)

print(*[int(x) for x in take], sep='')
