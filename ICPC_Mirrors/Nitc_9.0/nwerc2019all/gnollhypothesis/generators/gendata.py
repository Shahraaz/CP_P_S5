import math
import os
import random
import sys

MAX_N = 500
MAX_PREC = 10**8

CASE = 1
DEST = os.path.join(os.getcwd(), '../data/secret')

def format_prob(p):
    return ('%.6f' % p).rstrip('0').rstrip('.')

def next_file(short_desc=None, long_desc=None):
    global CASE
    basename = os.path.join(DEST, '%02d' % CASE)
    CASE += 1
    if short_desc is not None:
        basename += '-' + short_desc
    if long_desc is not None:
        with open(basename+'.desc', 'w') as desc_out:
            desc_out.write(long_desc)
    return open(basename+'.in', 'w')

def save_case(k, P, short_desc=None, long_desc=None, shuffle_adj_list=True):
    n = len(P)
    assert 1 <= k <= n
    assert abs(sum(P) - 100.0) < 1e-9
    assert min(P) >= 0.0
    sys.stderr.write('save case %d %d\n' % (n, k))
    f = next_file(short_desc, long_desc)
    f.write('%d %d\n' % (n, k))
    f.write('%s\n' % ' '.join(format_prob(p) for p in P))
    f.close()

def random_distribution(n):
    x = [0] + sorted(random.randint(0, MAX_PREC) for _ in range(n-1)) + [MAX_PREC]
    return [100.0*(x[i+1]-x[i])/MAX_PREC for i in range(n)]

def random_case(n, k, support_size=-1, support_consecutive=False):
    if support_size < 0: support_size = n
    P = random_distribution(support_size) + [0]*(n - support_size)
    if support_consecutive:
        i = random.randint(0, n-1)
        P = P[i:] + P[:i]
    else:
        random.shuffle(P)
    save_case(k, P, short_desc='n%d-k%d' % (n, k))
    

def main():
    random.seed(2019)

    random_case(1, 1)
    random_case(2, 1)
    random_case(2, 2)
    random_case(2, 2, 1)

    for i in range(10):
        n = random.randint(3, 20)
        k = random.randint(1, n)
        supp = random.randint(1, n)
        random_case(n, k, supp, support_consecutive=random.randint(0, 1))

    for _ in range(10):
        n = random.randint(50, 500)
        k = random.randint(1, min(100, n))
        supp = random.randint(1, n)
        random_case(n, k, supp, support_consecutive=random.randint(0, 1))
        
    sqrtn = int(math.sqrt(MAX_N))
    div = 2
    k = MAX_N/2
    supports = [1, MAX_N/100, MAX_N/10, MAX_N/2, MAX_N]
    while k >= 2:
        for supp in supports:
            random_case(MAX_N, k, support_size=supp)
        random_case(MAX_N, random.randint(k, 2*k),
                    support_size=random.randint(1, MAX_N),
                    support_consecutive=random.randint(0, 1))
        k /= 2
    random_case(MAX_N, 1, support_size=MAX_N/100, support_consecutive=1)
    random_case(MAX_N, MAX_N, support_size=MAX_N/2)
    
if __name__=='__main__':
    main()
