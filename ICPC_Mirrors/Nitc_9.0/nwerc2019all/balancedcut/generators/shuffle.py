#!/usr/bin/env python3

from random import randint

# Randomly swap left and right subtrees

n, k = map(int, input().split())
p = [int(input())-1 for _ in range(n)]

l = [-1] * n
r = [-1] * n
root = -1
for i in range(n):
    if p[i] < 0:
        root = i
    elif i < p[i]:
        l[p[i]] = i
    else:
        r[p[i]] = i

def shuffled_tree(u):
    a = shuffled_tree(l[u]) if l[u] != -1 else None
    b = shuffled_tree(r[u]) if r[u] != -1 else None

    if randint(0, 1) == 0:
        return [a, b]
    else:
        return [b, a]
    
t = shuffled_tree(root)

# Given a tree and a first index i, return (next_i, root, parents)
def to_parents(x, i = 0):
    i0 = i
    if x is None: return (i, None, [])
    i, rl, pl = to_parents(x[0], i)
    root = i
    i += 1
    i, rr, pr = to_parents(x[1], i)

    parents = pl + [-1] + pr
    if rl is not None: parents[rl-i0] = root+1 # translate to 1 based
    if rr is not None: parents[rr-i0] = root+1

    return i, root, parents


print(n, k)
print(*to_parents(shuffled_tree(root))[2], sep='\n')
