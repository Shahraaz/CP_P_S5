#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

# A graph that is simply a path from 1 to n where all edges have length 1.
# To this we add random edges with length equal to the original distance.

n = int(sys.argv[1])
m = int(sys.argv[2])

random_path = sys.argv[3] == 'random_path'

edges = []
added = {}
if random_path:
    for i in range(1, n):
        j = random.randint(0, i-1)
        edges.append((j, i, i-j))
        added[(j, i)] = True
else:
    for i in range(n-1):
        edges.append((i,i+1, 1))
        added[(i, i+1)] = True

while len(edges) < m:
    i, j = random.sample(range(n), 2)
    if i == j: continue
    if (i,j) in added or (j,i) in added: continue
    edges.append((i, j, abs(j-i)))
    added[(i,j)] = True

output_graph(n, edges)

