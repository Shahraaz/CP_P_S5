#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])


#  1---3---5---7--- 
#   \ / \ / \ /    ...
#    2   4   6


n_max = int(sys.argv[1])
m_max = int(sys.argv[2])
w = int(sys.argv[3])

triangles = min((n_max - 1) // 2, m_max // 3)
n = 1 + 2*triangles
m = 3*triangles

print(n,m)

for i in range(0,triangles):
    weights = [i+3, 1, i+1]
    if w != 0:
        for j in range(0,3):
            weights[j] = random.randint(1,w)
    print(2*i+1, 2*i+3, weights[0])
    print(2*i+1, 2*i+2, weights[1])
    print(2*i+2, 2*i+3, weights[2])

