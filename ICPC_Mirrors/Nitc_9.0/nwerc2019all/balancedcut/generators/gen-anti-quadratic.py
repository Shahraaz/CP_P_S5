import sys

# Just an upper bound on the number of nodes
n = 5*10**5 if len(sys.argv) < 2 else int(sys.argv[1])

extra_layer = False

minsize = [0, 1]
while minsize[-1] < 2*n:
    minsize.append(minsize[-1]+minsize[-2]+1)

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
    
def gen_complete(d):
    if d == 0: return []
    return merge(gen_complete(d-1), gen_complete(d-1))

def gen_mintree(d, extra_nodes=0, part=0):
    if minsize[d] + extra_nodes >= 2**d - 1:
        if extra_layer:
            T = gen_complete(d + 1)
        else:
            T = gen_complete(d)
        extra_nodes -= 2**d - 1 - minsize[d]
        return (T, extra_nodes)
    if d == 0: return ([], extra_nodes)
    assert d > 0
    (L, extra_nodes) = gen_mintree(d-1, extra_nodes, part=part if part else -1)
    if minsize[d-2] + extra_nodes >= minsize[d-1]:
        (R, extra_nodes) = gen_mintree(d-1, extra_nodes + minsize[d-2] - minsize[d-1], part=part if part else 1)
    else:
        (R, extra_nodes) = gen_mintree(d-2, extra_nodes, part = part if part else 1)
    return (merge(L, R), extra_nodes)

d = 2
while True:
    (T, rem) = gen_mintree(d, minsize[d+1]-1 -  minsize[d] if extra_layer else n-minsize[d])
    sys.stderr.write('%d %d\n' % (d, len(T)))
    if len(T) > n:
        d -= 1
        break
    f = T
    if extra_layer:
        k = minsize[d+1]-1
    else:
        k = n-1
    d += 1


n = len(f)
f = map(lambda x: x+1 if x >= 0 else x, f)

print n, k
print '\n'.join(map(str, f))

