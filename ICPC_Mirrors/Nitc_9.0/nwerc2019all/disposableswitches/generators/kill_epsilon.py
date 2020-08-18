#!/usr/bin/env python3
import sys
import random
from lib import *

# Builds a graph that is made up of three paths (ai,bi),
# where ai gives the number of edges and bi the total length.
# Each such path corresponds to a line ai*x + bi.

# The values are chosen so that the intersection points
# p12 (of lines 1 and 2) and p23 (of lines 2 and 3) are
# close to each other (relative difference < 1e-12).

# This should also work when we consider lines ai + bi*x instead.

seed(sys.argv[-1])

k = int(sys.argv[1])
swap = int(sys.argv[2])

wmax = 10**9

# This is the maximal value that still guarantees that all edges
# have length between 1 and wmax:
c = (k*wmax - 3*(k-1)) // (2*k-1)

(p1,q1) = (k, k*c-1)
(p2,q2) = (k-1, (k-1)*c-1)

assert(p2*q1 - p1*q2 == 1)

if swap:
    p1, p2 = p2, p1
    q1, q2 = q2, q1

(a1,b1) = (k, k*wmax)
(a2,b2) = (a1+p1, b1-q1)
(a3,b3) = (a2+p2, b2-q2)

n = a1 + a2 + a3 - 1

def path(count,total,offset):
    nodes = list(range(offset,offset+count-1))
    (p,q) = divmod(total,count)
    return list(zip([0] + nodes, nodes + [n-1], [p+1] * q + [p] * (count-q)))

es = path(a1,b1,1) + path(a2,b2,a1) + path(a3,b3,a1+a2-1)
output_graph(n, es)
