#!/usr/bin/env python
import collections

res = []
e = collections.defaultdict(list)
did = set()

def dfs(x, p=-1, depth=0):
  if depth > 400:
    return
  global res
  did.add(x)
  for y in e[x]:
    if y not in did:
      if x < 0:
        res += [(p, y, -x)]
      dfs(y, x, depth+1)

n = int(raw_input())
for i in range(1, n+1):
  for x in map(int, raw_input().split()[1:]):
    e[i] += [-x]
    e[-x] += [i]

for i in range(1, n+1):
  if i not in did:
    dfs(i)
if len(res) == n-1:
  for i in res:
    print ' '.join(map(str, i))
else:
  print 'impossible'
