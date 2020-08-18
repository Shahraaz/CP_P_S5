#!/usr/bin/env python3
t = sorted([int(round(100*float(x))) for x in input().split()])
o = int(round(100*float(input())))
best = (t[0] + t[1] + t[2])
worst = (t[1] + t[2] + t[3])
if 3*o < best: print('impossible')
elif 3*o >= worst: print('infinite')
else: print(f'{(3*o-t[1]-t[2])/100.:.2f}')
