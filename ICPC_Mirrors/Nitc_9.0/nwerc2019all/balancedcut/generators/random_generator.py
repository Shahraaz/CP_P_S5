#!/usr/bin/env python3
import random
import sys

# Recursively generate a tree of depth n by:
# 1. choosing the depths of the 2 child trees:
#       (d-1,d-1) with relative prob p -> full
#       (d-1,d-2) with relative prob q -> minimal left
#       (d-2,d-1) with relative prob r -> minimal right
def random_tree(d, p, q, r):
    if d <= 0: return None
    x = random.randint(0, p+q+r-1)
    if x < p:       dl, dr = d-1, d-1
    elif x < p+q:   dl, dr = d-1, d-2
    else:           dl, dr = d-2, d-1

    return [random_tree(dl, p, q, r), random_tree(dr, p, q, r)]

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

def print_tree(x):
    n, _, parents = to_parents(x)
    print(n, file=sys.stderr)
    assert n <= 500000
    print(n, random.randint(1, n-1))
    print(*parents, sep='\n')

print_tree(random_tree(24, 1, 1, 1))
