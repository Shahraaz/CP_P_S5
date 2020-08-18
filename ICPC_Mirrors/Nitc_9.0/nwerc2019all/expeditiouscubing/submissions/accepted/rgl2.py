#!/usr/bin/env python3

v = sorted(list(map(float, input().split())))
u = float(input()) + 1e-5

l = -1
r = u * 3 + 1
for i in range(400):
  m = (l + r) / 2.0
  if sum(sorted(v + [m])[1:4]) / 3.0 <= u:
    l = m
  else:
    r = m

print('infinite' if l > u * 3 else 'impossible' if l < 0 else '%.2f' % l)
