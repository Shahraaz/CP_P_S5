(n, k) = map(int, raw_input().split())
P = map(float, raw_input().split())
Bin = [[0 for j in range(n+1)] for i in range(n+1)]
for i in range(n+1):
    Bin[i][0] = Bin[i][i] = 1
    for j in range(1, i):
        Bin[i][j] = Bin[i-1][j-1]+Bin[i-1][j]
    
print ' '.join(map(str, [sum(P[i-j] * Bin[n-j-1][k-1] / Bin[n][k] for j in range(n-k+1)) for i in range(n)]))
