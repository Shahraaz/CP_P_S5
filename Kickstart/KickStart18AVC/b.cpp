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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, k;
#ifdef LOCAL
        n = 2e1, k = 1;
#else
        cin >> n >> k;
#endif
        vector<int> v(n);
        for (auto &x : v)
        {
#ifdef LOCAL
            x = Random<int>(1, 100)(rng);
#else
            cin >> x;
#endif
        }
        sort(all(v));
        vector<ll> sum(n);
        for (int i = 0; i < n; i++)
        {
            sum[i] = v[i];
            if (i > 0)
                sum[i] += sum[i - 1];
        }
        using ld = long double;
        ld prev = ((ld)sum[n - 1]) / n;
        auto sumRange = [&sum](int start, int end) -> ll {
            if (start > end)
                return 0;
            if (start == 0)
                return sum[end];
            return sum[end] - sum[start - 1];
        };
        int lptr = 0;
        pc(v);
        db(n, k);
        for (int i = 0; i < k; i++)
        {
            while (lptr < n && (v[lptr] - prev) <= 1e-6)
                ++lptr;
            db(lptr, prev, sumRange(lptr, n - 1));
            prev = (lptr * prev + sumRange(lptr, n - 1)) / n;
        }
        cout << fixed << setprecision(10) << prev << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef TIME
        // cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        // TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
