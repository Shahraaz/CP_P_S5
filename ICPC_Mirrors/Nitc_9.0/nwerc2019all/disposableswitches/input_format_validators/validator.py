import sys
import re

line = sys.stdin.readline()
assert re.match(r'^[1-9][0-9]* [1-9][0-9]*\n$', line)
n, m = map(int, line.strip().split())
assert 2 <= n <= 2000
assert 1 <= m <= 10000

es = set()

adj = [ [] for i in range(n) ]

for i in range(m):
    line = sys.stdin.readline()
    assert re.match(r'^[1-9][0-9]* [1-9][0-9]* [1-9][0-9]*\n$', line)
    u, v, w = map(int, line.strip().split())
    assert 1 <= u <= n
    assert 1 <= v <= n
    assert 1 <= w <= 10**9
    assert u != v
    assert (u,v) not in es
    assert (v,u) not in es
    es.add((u,v))
    adj[u-1].append(v-1)
    adj[v-1].append(u-1)

vis = [False]*n
vis[0] = True
S = [0]
while S:
    cur = S.pop()
    for nxt in adj[cur]:
        if not vis[nxt]:
            vis[nxt] = True
            S.append(nxt)

assert all(vis)

assert not sys.stdin.read()
sys.exit(42)
