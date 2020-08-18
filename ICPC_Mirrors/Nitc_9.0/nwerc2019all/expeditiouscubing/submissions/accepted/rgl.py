#!/usr/bin/env python3

v = sorted(list(map(lambda x: int(x.replace('.','')), input().split())))
u = int(input().replace('.',''))
if sum(v[1:]) <= u*3:
  print('infinite')
elif sum(v[:3]) > u*3:
  print('impossible')
else:
  print('%.2f' % ((u*3 - sum(v[1:3]))/100.0))
