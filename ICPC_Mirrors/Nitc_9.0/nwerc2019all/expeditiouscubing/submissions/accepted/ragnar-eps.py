#!/usr/bin/env python3
t = sorted([float(x) for x in input().split()])
o = float(input())
best = (t[0] + t[1] + t[2])/3
worst = (t[1] + t[2] + t[3])/3
if o < best-1e-4: print('impossible')
elif o >= worst-1e-4: print('infinite')
else: print(f'{3*o-t[1]-t[2]:.2f}')
