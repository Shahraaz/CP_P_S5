#!/usr/bin/env python3

n = input()
v = list(map(int, input().split()))
w = sorted(v)

i = 0
j = len(v) - 1
while i < j and v[i] == w[i]: i += 1
while i < j and v[j] == w[j]: j -= 1
v[i:j+1] = reversed(v[i:j+1])

if v == w:
  print(i+1, j+1)
else:
  print('impossible')
