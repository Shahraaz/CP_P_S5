import math
from fractions import Fraction

r = int(input())
n = 2*r
h = [0] * (n+1)
qs = []

s = 10
for i in range(2*r):
    h[i] = math.floor(-s * math.sqrt(r**2 - (i-r)**2))
    
    a = Fraction(-h[i], 10 * (2*r-i))
    if abs(a) <= 100 and 10 % a.denominator == 0:
        qs += [a]

hmin = min(h)
for i in range(n+1):
    h[i] -= hmin

print('%d %d' % (n,len(qs)))
print(' '.join(str(y) for y in h))
print('\n'.join('%.1f' % a for a in qs))
