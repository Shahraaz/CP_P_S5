#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

# A graph where there are vertices that are only visited when c = p/q
# number of nodes: 3*q+5
# number of edges: 3*q+6
# p,q must satisfy p+q+1 <= 10**9
# if near_miss == 1, then the lines only nearly intersect at c = p/q

p = int(sys.argv[1])
q = int(sys.argv[2])
near_miss = int(sys.argv[3])

num_edges = [2*q+2, q+2, 2]
tot_weight = [2*q+2, p+2*q+2 + near_miss, 2*p+2*q+2]
maxw = 10**9

n = 3*q + 5
m = 3*q + 6

print(n,m)
next_node = 2
for i in range(0,3):
    prev = 1
    for j in range(0,num_edges[i]):
        w = min(maxw, tot_weight[i] - (num_edges[i] - j - 1))
        tot_weight[i] -= w
        if j != num_edges[i]-1:
            print(prev, next_node, w)
            prev = next_node
            next_node += 1
        else:
            print(prev, n, w)
    