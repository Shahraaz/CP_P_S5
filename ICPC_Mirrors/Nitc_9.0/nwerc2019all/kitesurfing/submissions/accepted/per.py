import sys
(s, d, t) = map(int, raw_input().split())
n = 2+2*int(raw_input())
X = [0] + map(int, sys.stdin.read().split()) + [s]

def neg(x): return -x
def max_jump_at(X, i):
    j = i+1
    x = X[i]+d
    while x < X[-1]:
        while X[j] <= x: j += 1
        if j % 2 == 0 and X[j-1] < x: break
        x += (X[j]-x+d-1)/d*d
    return x-d
def max_jump(X): return [max_jump_at(X, i) for i in range(n)]

max_r = max_jump(X)
min_l = map(neg, reversed(max_jump(map(neg, reversed(X)))))

opt = [1<<60]*n
opt[n-1] = 0
for i in range(n-2, -1, -1):
    for j in range(i+1, n):
        if max_r[i] < min_l[j] - d: continue
        f = (X[j]-X[i]+d-1) / d
        opt[i] = min(opt[i], opt[j] + t*f)
        for k in range(i, j):
            if max_r[i] < X[k]: break
            if k % 2 or min_l[j] > X[k+1]: continue
            j1 = (X[k]-X[i]+d-1)/d
            j2 = (X[j]-X[k+1]+d-1)/d
            l1 = X[i] + j1*d
            l2 = X[j] - j2*d
            if l1 < l2:
                (f, r) = divmod(l2-l1, d)
                opt[i] = min(opt[i], opt[j] + t*(j1+j2) + min(d, t)*f + min(r, t))
print opt[0]
