// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
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
    while (*name == ',' || *name == ' ')
        name++;
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
    while (*names == ',' || *names == ' ')
        names++;
    const char *comma = strchr(names, ',');
    std::cerr.write(names, comma - names) << " { ";
    for (const auto &v : arg1)
        cerr << v << ' ';
    cerr << " }\n";
    PC(comma, args...);
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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 1e3 + 5, MOD = 1000000007;

int dp[2][NAX][NAX];
int a[NAX];
vector<int> p[NAX];

void solveCase(int caseNo)
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < NAX; i++)
        p[i].clear();
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        p[c].pb(a[i]);
    }
    int c = 0, b = 1;
    for (int i = 0; i <= k; i++)
        dp[c][i][0] = dp[c][i][1] = MOD;
    dp[c][0][0] = 0;
    for (int i = 0; i < NAX; i++)
    {
        if (p[i].empty())
            continue;
        sort(all(p[i]));
        swap(c, b);
        for (int j = 0; j <= k; j++)
        {
            dp[c][j][0] = dp[b][j][0];
            dp[c][j][1] = dp[b][j][1];
        }
        for (int j = 1; j <= p[i].size(); j++)
        {
            int x = p[i][j - 1];
            for (int d = 0; d + j <= k; d++)
            {
                dp[c][d + j][0] = min(dp[c][d + j][0], dp[b][d][0] + 2 * x);
                dp[c][d + j][1] = min(dp[c][d + j][1], dp[b][d][1] + 2 * x);
                dp[c][d + j][1] = min(dp[c][d + j][1], dp[b][d][0] + x);
            }
        }
    }
    cout << "Case #" << caseNo << ": " << dp[c][k][1] << '\n';
}

int main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    for (int i = 1; i <= t; ++i)
    {
        solveCase(i);
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
