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

class Solution
{
    string convert(string s)
    {
        string res;
        for (auto c : s)
        {
            if ('a' <= c && c <= 'z')
                res += c;
            else if ('A' <= c && c <= 'Z')
                res += c - 'A' + 'a';
            else if ('0' <= c && c <= '9')
                res += c;
        }
        return res;
    }

public:
    bool isPalindrome(string s)
    {
        s = convert(s);
        auto srev = s;
        reverse(srev.begin(), srev.end());
        return s == srev;
    }
};
#ifdef LOCAL
int main()
{
    Solution s;
}
#endif
