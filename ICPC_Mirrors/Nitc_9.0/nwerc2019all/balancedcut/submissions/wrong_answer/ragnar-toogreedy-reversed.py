#!/usr/bin/env python3
from math import log

# Whenever a node A is needed, first add all nodes that need to be present,
# going from close to A to close to the root / low in the tree to high in the
# tree.

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
            #print('set')
            first[u][d] = i
            firstfor[i].append((d,u))
        d += 1
        u = p[u]

#for x in first:
    #print('first  ', *x)
for i in range(n):
    firstfor[i] = reversed(sorted(firstfor[i]))
    #print('firstfor', *x)


take = [False] * n
s = 0

added = []

# Add the dependencies for u and then u itself
def visit(u):
    #print('visit', u)
    global s
    if s == k: return False
    if take[u]: return True

    for d, v in firstfor[u]:
        if v < u: continue # if we're on the right, no need to fix things
        # we're on the left, so need depth d-1 at the right of v
        if d == 1:
            # parent should already be taken
            assert take[p[u]]
            continue
        assert r[v] != -1
        visit(first[r[v]][d-2])
    if s == k: return False
    #print('Take', u)
    take[u] = True
    added.append(u)
    s += 1
    return True
    #print('visit', u, s)

# Walk the tree in pre-order.
def dfs(u):
    global added, s
    if s == k: return
    #print('dfs', u, l[u], r[u])
    added = []
    if not visit(u):
        pass
        #assert False
        #for x in added:
            #take[x] = False
            #s -= 1

    if l[u] != -1: dfs(l[u])
    if r[u] != -1: dfs(r[u])

dfs(root)

print(*[int(x) for x in take], sep='')
