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

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ITR(x, c) for (__typeof(c.begin()) x = c.begin(); x != c.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
//-------------------------------------------------------

class Solution2
{
public:
    int maxValueAfterReverse(vector<int> &V)
    {
        int N = V.size();
        ll S = 0;
        int i;
        FOR(i, N - 1)
        S += abs(V[i] - V[i + 1]);
        ll add = 0;
        ll hoge[4];
        FOR(i, 4)
        hoge[i] = -(1LL << 60);
        FOR(i, N - 1)
        {

            add = max(add, hoge[0] - (V[i + 1] + V[i]) - abs(V[i + 1] - V[i]));
            add = max(add, hoge[1] - (V[i + 1] - V[i]) - abs(V[i + 1] - V[i]));
            add = max(add, hoge[2] - (-V[i + 1] + V[i]) - abs(V[i + 1] - V[i]));
            add = max(add, hoge[3] - (-V[i + 1] - V[i]) - abs(V[i + 1] - V[i]));

            hoge[0] = max(hoge[0], V[i + 1] + V[i] - 1LL * abs(V[i + 1] - V[i]));
            hoge[1] = max(hoge[1], V[i + 1] - V[i] - 1LL * abs(V[i + 1] - V[i]));
            hoge[2] = max(hoge[2], -V[i + 1] + V[i] - 1LL * abs(V[i + 1] - V[i]));
            hoge[3] = max(hoge[3], -V[i + 1] - V[i] - 1LL * abs(V[i + 1] - V[i]));
        }

        // 端
        FOR(i, N - 1)
        add = max(add, 1LL * abs(V[N - 1] - V[i]) - abs(V[i + 1] - V[i]));
        FOR(i, N - 1)
        add = max(add, 1LL * abs(V[i + 1] - V[0]) - abs(V[i + 1] - V[i]));

        cout << S << " " << add << endl;
        return S + add;
    }
};

class Solution
{
public:
    int maxValueAfterReverse(vector<int> &V)
    {
        int n = V.size();
        ll S = 0;
        for (int i = 1; i < n; i++)
            S += llabs(V[i] - V[i - 1]);
        ll add = 0;
        ll hoge[4];
        for (int i = 0; i < 4; i++)
            hoge[i] = -1LL << 60;
        for (int i = 0; i < n - 1; i++)
        {
            add = max(add, hoge[0] - (V[i + 1] + V[i]) - llabs(V[i + 1] - V[i]));
            add = max(add, hoge[1] - (V[i + 1] - V[i]) - llabs(V[i + 1] - V[i]));
            add = max(add, hoge[2] - (-V[i + 1] + V[i]) - llabs(V[i + 1] - V[i]));
            add = max(add, hoge[3] - (-V[i + 1] - V[i]) - llabs(V[i + 1] - V[i]));

            hoge[0] = max(hoge[0], V[i + 1] + V[i] - llabs(V[i + 1] - V[i]));
            hoge[1] = max(hoge[1], V[i + 1] - V[i] - llabs(V[i + 1] - V[i]));
            hoge[2] = max(hoge[2], -V[i + 1] + V[i] - llabs(V[i + 1] - V[i]));
            hoge[3] = max(hoge[3], -V[i + 1] - V[i] - llabs(V[i + 1] - V[i]));
        }
        for (int i = 0; i < n; i++)
        {
            add = max(add, llabs(V[n - 1] - V[i]) - llabs(V[i + 1] - V[i]));
            add = max(add, llabs(V[i + 1] - V[0]) - llabs(V[i + 1] - V[i]));
        }
        return S + add;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif