#!/usr/bin/env python3
import random

def minimal_tree(depth, is_left, parents):
    if depth < 0: return -1
    sons = [-1] * 2

    if (is_left):
        depths = (depth - 1, depth - 2)
    else:
        depths = (depth - 2, depth - 1)

    sons[0] = minimal_tree(depths[0], is_left, parents)
    parents.append(-1)
    id = len(parents)
    sons[1] = minimal_tree(depths[1], is_left, parents)

    for x in sons:
        if x >= 1:
            parents[x - 1] = id

    return id

def full_tree(depth, parents):
    if depth < 0: return -1
    sons = [-1] * 2

    sons[0] = full_tree(depth - 1, parents)
    parents.append(-1)
    id = len(parents)
    sons[1] = full_tree(depth - 1, parents)

    for x in sons:
        if x >= 1:
            parents[x - 1] = id

    return id

# Example usage
# parents = []
# minimal_tree(3, False, parents)
# ... or ...
# full_tree(3, parents)

# n = len(parents)
# print(n, random.randint(1, n - 1))
# for x in parents:
#     print(x)
