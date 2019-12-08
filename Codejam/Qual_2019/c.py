import math
t = int(input())


def solve():
    n, L = map(int, input().split())
    enc = list(map(int, input().split()))
    diff_loc = -1
    for i in range(L-1):
        if enc[i] != enc[i+1]:
            diff_loc = i
            gcd = math.gcd(enc[i], enc[i+1])
            break
    mid_dec = [None]*(L+1)
    mid_dec[diff_loc + 1] = gcd
    mid_dec[diff_loc] = enc[diff_loc] // gcd
    mid_dec[diff_loc + 2] = enc[diff_loc + 1] // gcd
    for i in range(diff_loc-1, -1, -1):
        mid_dec[i] = enc[i] // mid_dec[i+1]
    for i in range(diff_loc+3, L+1):
        mid_dec[i] = enc[i-1] // mid_dec[i-1]
    primes = list(set(mid_dec))
    primes.sort()
    alpha_map = dict()
    for i in range(len(primes)):
        alpha_map[primes[i]] = chr(ord('A')+i)
    return ''.join([alpha_map[x] for x in mid_dec])


for _ in range(t):
    print("Case #{case_num}: {ans}".format(case_num=_+1, ans=solve()))
