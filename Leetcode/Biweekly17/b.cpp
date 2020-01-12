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
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int K)
    {
        ll temp = 0;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i <= K; i++)
            for (int j = 0; j <= K; j++)
                temp += mat[i][j];
        vector<vector<int>> ret(n, vector<int>(m));
        ret[0][0] = temp;
        for (int i = 0; i < n; i++)
        {
            ll temp1 = temp;
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                    continue;
                if (j + K < m)
                    for (int k = max(i - K, 0); k < min(n - 1, i + K); k++)
                        temp += mat[k][j + K];
                if ((j - K - 1) >= 0)
                    for (int k = max(i - K, 0); k < min(n - 1, i + K); k++)
                        temp -= mat[k][j - K - 1];
                mat[i][j] = temp;
            }
            temp = 0;
            for (int j = min(0, i - K); j <= max(n - 1, i + K); j++)
                for (int k = min(0, 0 - K); j <= max(m - 1, 0 + K); j++)
                    temp += mat[j][k];
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