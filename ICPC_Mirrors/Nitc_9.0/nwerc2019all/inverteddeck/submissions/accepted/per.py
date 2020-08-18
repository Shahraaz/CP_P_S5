n = int(raw_input())
X = map(int, raw_input().split())
Y = sorted(X)
d = [i for i in range(n) if X[i] != Y[i]]
(i, j) = (min(d), max(d)) if d else (0, 0)
X[i:j+1] = reversed(X[i:j+1])
if X == Y: print '%d %d' % (i+1, j+1)
else: print 'impossible'
