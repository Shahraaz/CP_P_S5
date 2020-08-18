#!/usr/bin/env python

def solve(x, v):
  n = len(x)
  m = len(v)
  used = set(v)
  res = []

  have = [0 for i in x]
  j = 0
  for i in range(n):
    while j > 0 and v[j-1] <= x[i][0]: j -= 1
    while j < m and v[j] < x[i][0]: j += 1
    while j < m and v[j] <= x[i][1]:
      j += 1
      have[i] += 1

  def greedy(i):
    if x[i][1] not in used and (i+1 == n or x[i+1][0] > x[i][1] or have[i+1] < 2): return x[i][1]
    if x[i][0] not in used and (i-0 <  0 or x[i-1][1] < x[i][0] or have[i-1] < 2): return x[i][0]
    for j in range(x[i][0]+1,x[i][1]):
      if j not in used:
        return j

  for i in range(n):
    while have[i] < 2:
      z = greedy(i)
      if z is not None:
        have[i] += 1
        if i+1 < n and x[i+1][0] == z: have[i+1] += 1
        if i-1 >=0 and x[i-1][1] == z: have[i-1] += 1
        used.add(z)
        res += [z]
      else:
        break

  if min(have) == 2 and max(have) == 2:
    return str(len(res)) + '\n' + ' '.join(map(str, res))
  else:
    return 'IMpossIBLE'

def main():
  n = int(raw_input())
  x = [map(int, raw_input().split()) for i in range(n)]
  m = int(raw_input())
  v = sorted(map(int, raw_input().split()))
  print solve(x, v)

if __name__ == '__main__':
  main()
