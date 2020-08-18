#!/usr/bin/env python
import collections

res = []
e = collections.defaultdict(list)
did = set()

def dfs(x, p=-1):
  global res
  did.add(x)
  for y in e[x]:
    if y not in did:
      if x < 0:
        res += [(p, y, -x)]
      dfs(y, x)

n = int(raw_input())
for i in range(1, n+1):
  for x in map(int, raw_input().split()[1:]):
    e[i] += [-x]
    e[-x] += [i]

dfs(1)
if len(res) == n-1:
  for i in res:
    print ' '.join(map(str, i))
else:
  print 'impossible'
