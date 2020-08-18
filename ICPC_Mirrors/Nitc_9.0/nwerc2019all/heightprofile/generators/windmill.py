import math
import fractions
import functools

def lcm(a,b):
    return a // fractions.gcd(a,b) * b

k = int(input())
m = functools.reduce(lcm, range(1,k+1), 1)

n = 2*m
h = [0] * (n+1)
qs = range(1,k+1)

for a in qs:
    for x in range(-m,m+1):
        y = 10*a*x
        if abs(y) <= 10*m:
            h[m+x] = y

hmin = min(h)
for i in range(n+1):
    h[i] -= hmin

print('%d %d' % (n,len(qs)))
print(' '.join(str(y) for y in h))
print('\n'.join('%.1f' % a for a in qs))
