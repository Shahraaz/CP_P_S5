#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;
const int MAX_N = 505;

int N, M, t[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    int cur, prv = N+1;
    for(int i=0; i<M; i++) {
        cin >> cur;
        t[prv][cur]++;
        prv = cur;
    }

    for(int i=1; i<=N+1; i++) for(int j=1; j<=N; j++)
        t[i][j] += t[i-1][j] + t[i][j-1] - t[i-1][j-1];

    auto c = [](int l1, int r1, int l2, int r2) { return t[r1][r2] - t[r1][l2-1] - t[l1-1][r2] + t[l1-1][l2-1]; };
    auto cost = [c](int l, int r) { return c(l, r, 1, N) + c(1, N+1, l, r) - 2*c(l, r, l, r); };

    for(int l=N; l>=1; l--) for(int r=l; r<=N; r++) {
        long long minc = INF;
        for(int u=l; u<=r; u++)
            minc = min(minc, dp[l][u-1] + dp[u+1][r]);
        dp[l][r] = cost(l, r) + minc;
    }

    cout << dp[1][N] - 1 << "\n";

    return 0;
}