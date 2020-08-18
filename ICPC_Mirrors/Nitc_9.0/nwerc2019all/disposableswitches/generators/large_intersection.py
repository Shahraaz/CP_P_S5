#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

# A graph with two potential shortest paths, whose lines intersect very far away.

n = int(sys.argv[1])
m = n
maxw = 10**9

print(n,m)
next_node = 2
num_edges = [(n+1)//2, (n+1)//2 - 1]
weights = [1,maxw]
for i in range(0,2):
    prev = 1
    for j in range(0,num_edges[i]):
        if j != num_edges[i]-1:
            print(prev, next_node, weights[i])
            prev = next_node
            next_node += 1
        else:
            print(prev, n, weights[i])

if n%2 == 0:
    print(random.randint(1,n-2), n-1, random.randint(1,maxw))
    