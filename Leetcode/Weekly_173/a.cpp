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

const int NAX = 1e3 + 5, MOD = 1000000007;

int cache[NAX][NAX];
class Solution
{
    bool isPalindrome(string str)
    {
        auto rev = str;
        reverse(all(rev));
        return str == rev;
    }
    string str;
    vector<vector<int>> cache;
    int solve(int start, int end)
    {
        if (start > end)
            return 0;
        if (start == end)
            return cache[start][end] = 1;
        int &ret = cache[start][end];
        if (ret >= 0)
            return ret;
        ret = 0;
        if (str[start] == str[end])
            ret = solve(start + 1, end - 1) + 2;
        ret = max(ret, solve(start + 1, end));
        ret = max(ret, solve(start, end - 1));
        return ret;
    }
    string ret(int start, int end)
    {
        if (start > end)
            return "";
        if (start == end)
            return str[start] + "";
        int &Ret = cache[start][end];
        if (str[start] == str[end])
        {
            if (Ret == solve(start + 1, end - 1))
                return str[start] + ret(start + 1, end - 1) + str[end];
        }
        if (Ret == solve(start + 1, end))
            return ret(start + 1, end);
        return ret(start, end - 1);
    }

public:
    int removePalindromeSub(string s)
    {
        if(isPalindrome(s))
            return 1;
        return 2;
        if (s == "")
            return 0;
        // memset(cache, -1, sizeof cache);
        cache.resize(s.length(), vector<int>(s.length(), -1));
        auto a = solve(0, s.length() - 1);
        auto substr = ret(0, s.length() - 1);
        cout << substr << '\n';
        string next = "";
        int i = 0, j = 0;
        while (j < substr.length())
        {
            if (s[i] == substr[j])
            {
                ++j;
                ++i;
            }
            else
            {
                next += s[i];
                ++i;
            }
        }
        auto Next = removePalindromeSub(next);
        return a + Next;
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