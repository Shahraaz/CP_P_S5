#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

# A graph that is simply a path from 1 to n.
# If shortcut == 1, then edges (1,i) are also added for each i > 2.
# If prefix_sum == 1, then edges (1,i) will have the same weight as the prefix sum of the other edges from 1 to i.

n = int(sys.argv[1])
min_weight = int(sys.argv[2])
max_weight = int(sys.argv[3])
shortcuts = int(sys.argv[4]) == 1
prefix_sum = int(sys.argv[5]) == 1

edges = []
for i in range(n-1):
    edges.append((i,i+1))

edges = with_random_weights(edges, min_weight=min_weight, max_weight=max_weight)

if shortcuts:
    if prefix_sum:
        sm = edges[0][2]
        for i in range(2,n):
            sm += edges[i-1][2]
            edges.append((0,i,sm))
            assert sm <= 10**9
    else:
        for i in range(2,n):
            edges.append((0,i,random.randint(min_weight, max_weight)))

output_graph(n, edges)

