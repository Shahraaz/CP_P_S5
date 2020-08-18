#!/usr/bin/env python3
import sys
import random
from lib import *

seed(sys.argv[-1])

N = 2000
M = 10000

n = 2
m = 0

path_lengths = []

i = 1
while n + (i-1) <= N and m + i <= M:
    n += i-1
    m += i
    path_lengths.append(i)
    i += 1

path_weights = []
for i in range(len(path_lengths)):
    path_weights.append(random.randint(0, 10**9))

path_weights = sorted(path_weights)[::-1]

curv = 1
es = []
for (l, w) in zip(path_lengths, path_weights):
    last = 0
    for i in range(l-1):
        es.append((last, curv, w // l + (1 if i < w % l else 0)))
        last = curv
        curv += 1
    es.append((last, n-1, w // l))

output_graph(n, es)

