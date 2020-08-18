#!/usr/bin/env python3

n = int(input())
v = [int(x) for x in input().split()]
if v==sorted(v):
    print(1,1)
    exit()
s, t = n, 0
for i in range(n-1):
    if v[i] >= v[i+1]:
        s, t = min(s, i), max(t, i)
v = v[:s] + list(reversed(v[s:t+2])) + v[t+2:]
if v == sorted(v): print(s+1, t+2)
else: print('impossible')
