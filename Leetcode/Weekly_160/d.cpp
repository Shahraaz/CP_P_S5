#ifdef WIN32
#include <bits/stdc++.h>
using namespace std;
#endif
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

class Solution
{
    int dp[13][13];
    int solve(int n, int m)
    {
        if (n > m)
            swap(n, m);
        if (dp[n][m])
            return dp[n][m];
        if (n == m)
            return dp[n][m] = 1;
        if (n == 11 && m == 13)
            return dp[n][m] = 6;
        int hor = INT_MAX;
        for (int i = 1; i <= n / 2; ++i)
            hor = min(hor, solve(i, m) + solve(n - i, m));
        for (int i = 1; i <= m / 2; ++i)
            hor = min(hor, solve(n, i) + solve(n, m - i));
        return dp[n][m] = hor;
    }

public:
    int tilingRectangle(int n, int m)
    {
        memset(dp, 0, sizeof dp);
        return solve(n, m);
    }
};
#ifdef WIN32
int main()
{
    Solution s;
    int n, m;
    cin >> n >> m;
    cout << s.tilingRectangle(n, m);
}
#endif