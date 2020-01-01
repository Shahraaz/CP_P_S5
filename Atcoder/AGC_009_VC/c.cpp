// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
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

const int NAX = 2e5 + 5, MOD = 1000000007;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
    return a;
}

ll a[NAX];
ll dp[NAX];

void solveCase(int caseNo)
{
    ll n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (x > y)
        swap(x, y);
    a[0] = a[1] - y;
    a[n + 1] = a[n] + y;
    n += 2;
    ll bal = 0;
    for (int i = 0; i + 2 < n; ++i)
        if (a[i + 2] - a[i] < x)
        {
            cout << 0 << '\n';
            return;
        }
    int p1, p2;
    p1 = p2 = 0;
    dp[0] = add(dp[0], 1);
    dp[1] = sub(dp[1], 1);
    for (int i = 0; i < n; ++i)
    {
        bal = add(bal, dp[i]);
        if (i == n - 1)
            break;
        if (p1 <= i + 1)
        {
            p1 = i + 2;
            while (p1 < n && a[p1] - a[p1 - 1] >= x)
                ++p1;
        }
        while (p2 < n && a[p2] - a[i] < y)
            ++p2;
        if (p2 > p1)
            continue;
        dp[p2] = add(dp[p2], bal);
        dp[p1 + 1] = sub(dp[p1 + 1], bal);
    }
    cout << bal << '\n';
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
