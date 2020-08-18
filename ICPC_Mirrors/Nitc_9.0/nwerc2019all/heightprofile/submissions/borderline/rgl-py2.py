#!/usr/bin/env python2

n, k = map(int, raw_input().split())
n += 1
w = list(map(int, raw_input().split()))

def solve(inc):
  for v in (w, [-i for i in w[::-1]]):
    seen = [(0, v[0])]
    j = 0
    for i in range(1, n):
      lef = -1
      for r in range(20, -1, -1):
        if lef+2**r < len(seen) and v[i]-i*inc - seen[lef+2**r][1] < 0:
          lef += 2**r
      if lef+1 < len(seen):
        bx = seen[lef+1][0]
        by = v[i]-i*inc - (v[bx]-bx*inc)
        ax = (bx-1 if bx>0 else bx)
        ay = v[i]-i*inc - (v[ax]-ax*inc)
        if by >= 0:
          x = ax + (bx-ax) * (-ay) / float(by - ay) if ay < 0 else bx
          yield i - x
      if v[i]-i*inc < seen[-1][1]:
        seen += [(i, v[i]-i*inc)]

  yield -1

for z in range(k):
  res = max(solve(int(float(raw_input())*10)))
  print res if res != -1 else 'impossible'
