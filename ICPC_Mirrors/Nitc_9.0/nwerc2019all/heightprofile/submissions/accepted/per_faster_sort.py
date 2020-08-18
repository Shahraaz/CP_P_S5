(n, k) = map(int, raw_input().split())
H = map(int, raw_input().split())

def solve(q):
    C = sorted((q*i-H[i])*(n+1)-i for i in range(n+1))
    mi = ans = 0
    for c in C:
        i = (-c) % (n+1)
        d = min(q+H[i-1]-H[i] if i else 1e30, H[mi]-H[mi+1]+q if mi < n else 1e30)
        if d > 0:
            ans = max(ans, mi-i + min(1.0, 1.0*(q*(i-mi)+H[mi]-H[i])/d))
        mi = max(mi, i)
    return ans if ans else 'impossible'

for _ in range(k):
    print solve(int(round(10*float(raw_input()))))
