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

class Solution
{
public:
    int oddEvenJumps(vector<int> &A)
    {
        int n = A.size();
        vector<int> dpOdd(n, -1), dpEven(n, -1);
        dpOdd[n - 1] = dpEven[n - 1] = 1;
        map<int, int> mp;
        mp[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            auto it = mp.lower_bound(A[i]);
            if (it != mp.end())
            {
                // cout << i << ' ' << it->f << ' ' << it->s << '\n';
                dpOdd[i] = dpEven[it->s];
            }
            else
            {
                // cout << i << ' ' << 0 << '\n';
                dpOdd[i] = 0;
            }
            if (it != mp.end())
            {
                if (it->f == A[i])
                {
                    // cout << "a\n";
                    // cout << i << '~' << it->f << ' ' << it->s << '\n';
                    dpEven[i] = dpOdd[it->s];
                }
                else
                {
                    if (it == mp.begin())
                    {
                        // cout << "b\n";
                        // cout << i << '~' << 0 << '\n';
                        dpEven[i] = 0;
                    }
                    else
                    {
                        --it;
                        // cout << "c\n";
                        // cout << i << '~' << it->f << ' ' << it->s << '\n';
                        dpEven[i] = dpOdd[it->s];
                    }
                }
            }
            else
            {
                --it;
                // cout << "d\n";
                // cout << i << '~' << it->f << ' ' << it->s << '\n';
                dpEven[i] = dpOdd[it->s];
            }
            mp[A[i]] = i;
        }
        int ret = 0;
        // cout << '\n';
        for (size_t i = 0; i < n; i++)
        {
            // cout << i << ' ' << dpOdd[i] << ' ' << dpEven[i] << '\n';
            ret += dpOdd[i];
        }
        return ret;
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