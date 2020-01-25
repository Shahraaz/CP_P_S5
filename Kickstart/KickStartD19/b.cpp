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

const int NAX = 1e5 + 5, MOD = 1000000007;

int h[NAX], lef[NAX], rig[NAX], cntl[NAX], cntr[NAX];
char c[NAX];

void solveCase(int caseNo)
{
    int n, g, m;
    cin >> n >> g >> m;
    for (int i = 0; i < g; i++)
    {
        cin >> h[i] >> c[i];
        h[i] %= n;
    }
    fill(lef, lef + n, -1);
    fill(rig, rig + n, -1);
    for (int i = 0; i < g; i++)
    {
        if (c[i] == 'C')
        {
            int now = (h[i] + m) % n;
            rig[now] = m;
        }
        else
        {
            int now = (h[i] - m) % n;
            if (now < 0)
                now += n;
            lef[now] = m;
        }
    }
    int cur = -1;
    for (int i = 0; i < n * 2; i++)
    {
        cur = max(cur - 1, lef[i % n]);
        lef[i % n] = cur;
        //         db(i, cur);
        // #ifdef LOCAL
        //         cout << "lef ";
        //         for (int i = 0; i < g; ++i)
        //             cout << lef[i] << ' ';
        //         cout << '\n';
        // #endif
    }
    cur = -1;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        cur = max(cur - 1, rig[i % n]);
        rig[i % n] = cur;
        //         db(i, cur);
        // #ifdef LOCAL
        //         cout << "rig ";
        //         for (int i = 0; i < g; ++i)
        //             cout << rig[i] << ' ';
        //         cout << '\n';
        // #endif
    }
    fill(cntl, cntl + n, 0);
    fill(cntr, cntr + n, 0);
    for (int i = 0; i < n; i++)
    {
        int res = max(lef[i], rig[i]);
        if (res < 0)
            continue;
        if (lef[i] == res)
        {
            int pos = (i + res) % n;
            ++cntl[pos];
        }
        if (rig[i] == res)
        {
            int pos = (i - res) % n;
            if (pos < 0)
                pos += n;
            ++cntr[pos];
        }
    }
    cout << "Case #" << caseNo << ": ";
    for (size_t i = 0; i < g; i++)
    {
        int ans = 0;
        if (c[i] == 'C')
            ans = cntr[h[i] % n];
        else
            ans = cntl[h[i] % n];
        cout << ans << ' ';
    }
    cout << '\n';
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
