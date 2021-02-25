#include <bits/stdc++.h>

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> par(n - 1);
    for (auto &v : par)
    {
        cin >> v;
        --v;
    }
    vector<vector<int>> g(n);
    for (int v = 1; v < n; ++v)
    {
        g[par[v - 1]].push_back(v);
    }
    vector<int> sz(n, 1);
    vector<int> f(n, 1);
    const auto rec = [&](auto &&rec, int v) -> void {
        int sum = 0;
        vector<int> seq;
        for (const auto &w : g[v])
        {
            rec(rec, w);
            sz[v] += sz[w];
            if (sz[w] % 2)
            {
                // case 3
                seq.push_back(-f[w]);
            }
            else
            {
                if (f[w] < 0)
                {
                    // case 1
                    f[v] -= -f[w];
                }
                else
                {
                    // case 2
                    sum += -f[w];
                }
            }
        }
        sort(seq.begin(), seq.end(), greater<int>());
        seq.push_back(sum);
        db(v, seq, sum);
        for (int i = 0; i < (int)seq.size(); ++i)
        {
            if (i % 2)
            {
                f[v] += seq[i];
            }
            else
            {
                f[v] -= seq[i];
            }
        }
        db(v, f[v]);
    };
    rec(rec, 0);
    cout << (n + f[0]) / 2 << endl;
    return 0;
}
