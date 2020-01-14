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

const int NAX = 20000 + 5, MOD = 1000000007;

int dp[NAX][101];

class Solution
{
    string S, T;
    int solve(int idx1, int idx2)
    {
        if (idx2 == T.length())
            return idx1;
        if (idx1 == S.length())
            return MOD;
        int &ret = dp[idx1][idx2];
        if (ret >= 0)
            return ret;
        ret = solve(idx1 + 1, idx2);
        if (S[idx1] == T[idx2])
            ret = min(ret, solve(idx1 + 1, idx2 + 1));
        return ret;
    }

public:
    string minWindow(string S, string T)
    {
        memset(dp, -1, sizeof dp);
        this->S = S;
        this->T = T;
        int idx, len;
        idx = -1, len = MOD;
        for (int i = 0; i < S.length(); i++)
            if (S[i] == T[0])
            {
                int temp = solve(i + 1, 1);
                int templen = temp - i;
                if (templen < S.length() && templen < MOD)
                    if (len > templen)
                    {
                        len = templen;
                        idx = i;
                    }
            }
        if (len < S.length())
            return S.substr(idx, len);
        return "";
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