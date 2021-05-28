#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

long long T, N, B, K;

int read()
{
    int x;
    cin >> x;
    // db(x);
    assert(0 <= x && x <= 9);
    return x;
}

void solveCase()
{
    vector<int> ht(N);
    db(T, N, B, K, ht);
    for (size_t i = 0; i < N * B; i++)
    {
        int now = read();
        db(i, now, ht);
        int next = -1;
        for (size_t j = 0; j < N; j++)
        {
            if (ht[j] == B)
                continue;
            if (now == 9)
            {
                if (next == -1 || ht[next] < ht[j])
                    next = j;
            }
            else if (now >= 8)
            {
                if ((ht[j] < (B - 1) && (next == -1 || ht[next] < ht[j])))
                    next = j;
            }
            else if ((ht[j] < (B - 2) && (next == -1 || ht[next] < ht[j])))
                next = j;
        }
        if (next == -1)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (ht[j] == B)
                    continue;
                if (ht[j] < B - 1 && (next == -1 || (ht[next] < ht[j])))
                    next = j;
            }
        }
        if (next == -1)
        {
            for (size_t j = 0; j < N; j++)
            {
                if (ht[j] == B)
                    continue;
                if ((next == -1 || (ht[next] < ht[j])))
                    next = j;
            }
        }
        db(next);
        assert(next != -1);
        cout << next + 1 << endl;
        ht[next]++;
    }
}

int32_t main()
{
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    cin >> T >> N >> B >> K;
    t = T;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}