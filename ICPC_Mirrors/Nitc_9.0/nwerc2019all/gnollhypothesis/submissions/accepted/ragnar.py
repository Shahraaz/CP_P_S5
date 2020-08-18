#!/usr/bin/env python3

n, k = [int(x) for x in input().split()]
p = [float(x) for x in input().split()]

# The number of ways for a streak of 0<=i<=n-k non-chosen monsters is
# binom(n-i-1, k-1)
streak = [1] * (n-k+1)
for i in range(n-k-1, -1, -1):
    streak[i] = streak[i+1] * (n-i-1) // (n-i-k)

nck = sum(streak) # From hockey-stick identity

# Convolve the input sequence with the streak probabilities. Could be sped up by
# using FFT and using C++ (although python has arbitrary precision Decimal).
ans = [0]*n
for i in range(n):
    for j in range(n-k+1):
        ans[i] += p[(i-j+n)%n] * streak[j]/nck

print(*ans)
