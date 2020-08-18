n = int(raw_input())
X = map(int, raw_input().split())
i = 0
while i+1 < n and X[i] <= X[i+1]: i += 1
j = i+1
while i > 0 and X[i-1] == X[i]: i -= 1
while j < n and X[j] <= X[j-1]: j += 1

if j < n and X[j] < X[i]: print 'impossible'
elif i == n: print '1 1'
else: print '%d %d' % (i+1, j)
