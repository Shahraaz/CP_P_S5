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

const int NAX = 2e5 + 5, MOD = 1000000007;

pair<int, int> tolol[NAX];
int x[NAX], c[NAX];

void solveCase(int caseNo)
{
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
        cin >> tolol[i].f;
    for (int i = 1; i <= n; i++)
        cin >> tolol[i].s;
    sort(tolol + 1, tolol + 1 + n);
    for (int i = 1; i <= n; i++)
        x[i] = tolol[i].f, c[i] = tolol[i].s;
    ordered_set<pair<long long, long long>> left, right;
    long long lef = k / 2, rig = (k + 1) / 2;
    long long sum = 0;
    int cntr = 0;
    for (int i = 1; i <= lef; i++)
    {
        left.insert({c[i] - x[i], ++cntr});
        sum += c[i] - x[i];
    }
    for (int i = lef + 1; i <= n; i++)
        right.insert({c[i] + x[i], ++cntr});
    auto it = right.begin();
    for (int i = 0; i < rig; i++)
    {
        sum += it->f;
        ++it;
    }
    ll ans = LLONG_MAX;
    for (int i = lef + 1; i <= n - rig; i++)
    {

        if (right.order_of_key({c[i] + x[i], 0}) < rig)
        {
            sum -= c[i] + x[i];
            sum += (*right.find_by_order(rig)).f;
        }
        right.erase(right.lower_bound({c[i] + x[i], 0}));
        ans = min(ans, sum + lef * x[i] - rig * x[i] + c[i]);
        left.insert({c[i] - x[i], ++cntr});
        if (left.order_of_key({c[i] - x[i], 0}) < lef)
        {
            sum += c[i] - x[i];
            sum -= (*left.find_by_order(lef)).f;
        }
    }
    cout << ans << '\n';
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
        cout << "Case #" << i << ": ";
        solveCase(i);
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
