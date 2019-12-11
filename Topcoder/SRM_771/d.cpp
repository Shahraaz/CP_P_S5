//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

class TwoMonthScheduling
{
public:
    int minimumMonths(int workers, vector<int> firstMonth0, vector<int> firstMonth1, vector<int> secondMonth0, vector<int> secondMonth1)
    {
        int L0 = firstMonth0.size();
        int L1 = firstMonth1.size();
        int n = L0 * L1;
        vector<int> a(n), b(n);
        for (int i1 = 0; i1 < L1; ++i1)
            for (int i0 = 0; i0 < L0; ++i0)
            {
                a[i1 * L0 + i0] = min(workers, firstMonth0[i0] ^ firstMonth1[i1]);
                b[i1 * L0 + i0] = min(workers, secondMonth0[i0] ^ secondMonth1[i1]);
            }
        const int inf = mod;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf));
        dp[0][0] = 0;
        for (int r = 0; r <= n; ++r)
        {
            long long sum_b = accumulate(b.begin(), b.begin() + r, 0);
            vector<int> pmin(n + 1);
            pmin[r] = dp[r][r];
            for (int i = r - 1; i >= 0; --i)
                pmin[i] = min(pmin[i + 1], dp[i][r]);
            int ptr = 0;
            long long sum_a = 0;
            for (int new_r = r; new_r <= n; ++new_r)
            {
                while (ptr < r && sum_a + sum_b > workers)
                    sum_b -= b[ptr++];
                if (sum_a + sum_b <= workers)
                    dp[r][new_r] = min({dp[r][new_r], dp[r][r] + 1, pmin[ptr] + 1});
                if (new_r < n)
                    sum_a += a[new_r];
            }
        }
        return dp[n][n];
    }
};

#ifndef LOCAL
<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    auto TimeStart = chrono::steady_clock::now();
#ifdef multitest
    cin >> t;
#endif
#ifdef TIME
    cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
    return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!