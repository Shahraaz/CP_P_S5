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
    int totalFruit(vector<int> &tree)
    {
        int n = tree.size();
        vector<vector<int>> inidicesOfFruits(n);
        vector<int> nextDifferntFruit(n);
        db("A");
        for (size_t i = 0; i < tree.size(); i++)
            inidicesOfFruits[tree[i]].pb(i);
        db("B");
        for (int i = tree.size() - 1; i >= 0; i--)
        {
            db(i);
            if (i == tree.size() - 1)
                nextDifferntFruit[i] = tree.size();
            else if (tree[i] == tree[i + 1])
                nextDifferntFruit[i] = nextDifferntFruit[i + 1];
            else
                nextDifferntFruit[i] = i + 1;
        }
        int res = 0;
        for (int i = 0; i < tree.size(); i++)
        {
            if (nextDifferntFruit[i] == n)
                res = max(res, n - i);
            else
            {
                int a = tree[i], b = tree[nextDifferntFruit[i]];
                int left = i, right = n - 1, curr = 0;
                while (left <= right)
                {
                    int mid = (left + right) / 2;
                    auto cnt = [&inidicesOfFruits](int elem, int start, int end) -> int {
                        return upper_bound(all(inidicesOfFruits[elem]), end) - lower_bound(all(inidicesOfFruits[elem]), start);
                    };
                    if (cnt(a, i, mid) + cnt(b, i, mid) == (mid - i + 1))
                    {
                        curr = max(curr, mid - i + 1);
                        left = mid + 1;
                    }
                    else
                        right = mid - 1;
                }
                res = max(res, curr);
            }
        }
        return res;
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &x : v)
        {
            cin >> x;
        }
        cout << S.totalFruit(v) << '\n';
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif