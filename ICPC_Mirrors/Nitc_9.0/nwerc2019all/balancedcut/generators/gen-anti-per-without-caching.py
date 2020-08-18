import sys

n = 5*10**5 if len(sys.argv) < 2 else int(sys.argv[1])

def merge(L, R):
    n = len(L) + len(R) + 1
    f = [-1]*n
    for i in range(len(L)):
        if L[i] == -1: f[i] = len(L)
        else: f[i] = L[i]
    for i in range(len(R)):
        if R[i] == -1: f[i+len(L)+1] = len(L)
        else: f[i+len(L)+1] = R[i] + len(L) + 1
    return f
    

def gen_mintree(d):
    if d == 0: return []
    if d == 1: return [-1]
    return merge(gen_mintree(d-1), gen_mintree(d-2))

def gen_complete(n):
    if n == 0: return []
    if n == 1: return [-1]
    cn = 0
    while 1 + 2*(1 + 2*cn) < n: cn = 1 + 2*cn
    rem = n - 1 - 2*cn
    reml = min(rem, cn+1)
    remr = rem - reml
    assert(1+2*cn + reml + remr == n)
    return merge(gen_complete(cn + reml), gen_complete(cn + remr))

minsize = [0, 1, 2]
d = 1
while minsize[d-1] + ((1<<d)-1) + 1 < n:
    minsize.append(minsize[-1]+minsize[-2]+1)
    d += 1

R = gen_mintree(d-1)
nL = n - 1 - len(R)
assert nL > (1<<(d-1))-1
L = gen_complete(nL)
assert len(L) == nL

f = merge(L, R)
assert len(f) == n
f = map(lambda x: x+1 if x >= 0 else x, f)

k = minsize[d+1]-1

sys.stderr.write('Tree depth = %d, Right subtree size %d, Left subtree size %d, k = %d\n' % (d+1, len(R), nL, k))

print n, k
print '\n'.join(map(str, f))

