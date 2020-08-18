n = int(raw_input())
L = [0]*n
R = [0]*n
for i in range(n):
    (L[i], R[i]) = map(int, raw_input().split())

p = int(raw_input())
X = map(int, raw_input().split())
C = [0]*n
M = [0]*n
j = 0
for i in range(n):
    M[i] = L[i]+1
    while M[i] in X: M[i] += 1
    while j < p and X[j] < R[i]:
        C[i] += X[j] >= L[i]
        j += 1
    if j < p and X[j] == R[i]: C[i] += 1

Y = []
for i in range(n):
    if L[i] in Y: C[i] += 1
    t = R[i] - (i+1 < n and C[i+1] == 2)
    while C[i] < 2:
        while t >= L[i] and t in X+Y: t -= 1
        Y.append(t)
        C[i] += 1

if max(C) > 2: print 'impossible'
else:
    print len(Y)
    print ' '.join(map(str, Y))
