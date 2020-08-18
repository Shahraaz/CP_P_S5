#!/usr/bin/env python3

# Read an input file and adds one extra leaf into the tree at the position set
# below.
# 0-based parent id
parent = 186829
left_child = False

n, k = map(int, input().split())
ps = [int(input())-1 for _ in range(n)]

for i in range(n):
    if ps[i] > parent:
        ps[i] += 1
    if ps[i] == parent and left_child:
        ps[i] += 1

pos = parent if left_child else parent+1
ps = ps[ : pos] + [parent+1 if left_child else parent+0] + ps[pos : ]

print(len(ps), k)
for x in ps:
    print(x+1)

