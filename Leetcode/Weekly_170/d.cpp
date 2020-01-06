#include <bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
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
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
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
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

ll cache[501][501];
class Solution
{
    string text;
    int n;
    ll dp(int start, int end)
    {
        int len = end - start + 1;
        if (len < 0)
            return 0;
        else if (len == 1)
            return 0;
        auto &ret = cache[start][end];
        if (ret >= 0)
            return ret;
        ret = dp(start + 1, end) + 1;
        ret = min(ret, dp(start, end - 1) + 1);
        if (text[start] == text[end])
            ret = min(ret, dp(start + 1, end - 1));
        return ret;
    }

public:
    int minInsertions(string s)
    {
        text = s;
        n = s.length();
        memset(cache, -1, sizeof cache);
        return dp(0, n - 1);
    }
};
#ifdef LOCAL
int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.minInsertions(str);
}
#endif
