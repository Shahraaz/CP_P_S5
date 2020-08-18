#!/usr/bin/env python

n,m = map(int, raw_input().split())
v = map(float, raw_input().split()) * 2
m = n - m

def nck(n,k):
  return 1 if k == 0 or k == n else nck(n-1,k-1)*float(n)/k

chall = nck(n,m)
chwith = [nck(n-i-1,m-i+1) / float(chall) if 0<i<=m+1 else 0 for i in range(n+1)]
for i in range(1,len(v)): v[i] += v[i-1]

chum = sum(chwith[1:])
res = [v[i+n] * chum for i in range(n)]
for i in range(n):
  for j in range(n+1):
    res[i] -= v[i+n-j] * chwith[j]

print ' '.join(map(str, res))
