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

const int NAX = 4e4 + 5, MOD = 1000000007, NAX2 = int(4e5 + 10);

ll dp[int(4e5 + 10)];

void solveCase(int caseNo)
{
    int n, x, y, z;
    cin >> n;
    vector<tuple<int, int, int>> a;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y >> z;
        a.pb(make_tuple(y, x, z));
    }
    // db("a");
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y >> z;
        a.pb(make_tuple(y, -x, z));
    }
    // db("b");
    sort(all(a));
    // reverse(all(a));
    dp[0] = 0;
    for (int i = 1; i < NAX2; ++i)
        dp[i] = -1e18;
    int s = 0;
    // db("c");
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int w = get<1>(a[i]);
        int c = get<2>(a[i]);
        // db(i, w, c);
        if (w > 0)
        {
            for (int j = s; j >= 0; --j)
                dp[j + w] = max(dp[j + w], dp[j] - c);
            s += w;
        }
        else
        {
            w = -w;
            for (int j = w; j <= s; ++j)
                dp[j - w] = max(dp[j - w], dp[j] + c);
        }
    }
    db("d");
    cout << *max_element(dp, dp + s + 1) << '\n';
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