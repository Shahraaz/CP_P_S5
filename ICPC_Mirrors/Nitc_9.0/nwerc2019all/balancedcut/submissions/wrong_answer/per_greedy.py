import sys

(n, k) = map(int, sys.stdin.readline().split())
f = [0] + map(int, sys.stdin.read().split())

min_size = [0, 1]
while min_size[-1] < n:
    min_size.append(min_size[-2] + min_size[-1] + 1)

root = f.index(-1)
children = [[0, 0] for _ in range(n+1)]
for i in range(1, n+1):
    if i != root:
        children[f[i]][i > f[i]] = i

height = [0]*(n+1)
size = [0]*(n+1)
def dfs(u):
    (l, r) = children[u]
    if l: dfs(l)
    if r: dfs(r)
    height[u] = max(height[l], height[r]) + 1
    size[u] = size[l] + size[r] + 1

dfs(root)

keep = [-1]*(n+1)
for u in range(1, n+1):
    if keep[u] != -1: continue
    sz = h = 1
    v = u
    while v != root:
        w = f[v]
        if keep[w] == 0: sz = k+1
        if w < v:
            sz += size[w] - size[v]
            h = max(h, height[children[w][0]])
        else:
            sz += min_size[h-1] + 1
        h += 1
        v = w
    v = u
    if sz <= k:
        keep[u] = 1
        while v != root:
            v = f[v]
            keep[v] = 1
    else:
        keep[u] = height[u] = size[u] = 0
        while v != root:
            v = f[v]
            if keep[v]:
                (l, r) = children[v]
                height[v] = max(height[l], height[r]) + 1
                size[v] = size[l] + size[r] + 1

print ''.join(map(str, keep[1:]))
