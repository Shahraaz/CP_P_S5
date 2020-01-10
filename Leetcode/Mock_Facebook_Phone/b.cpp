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
    bool isPalindromeRange(string &s, int i, int j)
    {
        for (int k = i; k <= i + (j - i) / 2; k++)
            if (s[k] != s[j - k + i])
                return false;
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
            if (s[i] != s[s.length() - 1 - i])
            {
                int j = s.length() - 1 - i;
                cout << i << ' ' << j << '\n';
                return isPalindromeRange(s, i + 1, j) || isPalindromeRange(s, i, j - 1);
            }
        return true;
    }
};

#ifdef LOCAL
int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.validPalindrome(str);
}
#endif