import heapq
import sys

(n, k) = map(int, sys.stdin.readline().split())
f = [0] + map(int, sys.stdin.read().split())

root = f.index(-1)
children = [[0, 0] for _ in range(n+1)]
for i in range(1, n+1):
    if i != root:
        children[f[i]][i > f[i]] = i

height = [0]*(n+1)
def dfs(u):
    (l, r) = children[u]
    if l: dfs(l)
    if r: dfs(r)
    height[u] = max(height[l], height[r]) + 1

dfs(root)

keep = [0]*(n+1)
curh = [0]*(n+1)
avail = [root]
incpool = [None]*(n+1)

def incheight(u, h, res):
    if h <= curh[u]: return
    if not keep[u]: res.append(u)
    (l, r) = children[u]
    if h-1 > height[l]: (l, r) = (r, l)
    incheight(l, h-1, res)
    incheight(r, h-2, res)
    
while k > 0:
    u = heapq.heappop(avail)
    if keep[u]: continue
    take = [u]
    incpool[u] = [u]
    tot_take = 1
    while u != root:
        v = f[u]
        o = sum(children[v]) - u
        if curh[o] > curh[u]: break
        if curh[o] < curh[u]:
            if incpool[o] is None:
                incpool[o] = []
                incheight(o, curh[u], incpool[o])
            take.append(o)
            tot_take += len(incpool[o])
        u = v
    if tot_take > k: continue
    k -= tot_take
    for v in take:
        for u in incpool[v]:
            (l, r) = children[u]
            if l: heapq.heappush(avail, l)
            if r: heapq.heappush(avail, r)
            curh[u] = keep[u] = 1
            while u != root:
                incpool[u] = None
                if curh[f[u]] >= curh[u]+1: break
                u = f[u]
                curh[u] += 1


print ''.join(map(str, keep[1:]))
