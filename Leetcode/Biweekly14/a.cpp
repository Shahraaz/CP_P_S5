#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;
#endif
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
    ll stoil(string s)
    {
        ll ret = 0;
        for (auto c : s)
            ret = ret * 10 + c - '0';
        return ret;
    }

public:
    string toHexspeak(string num)
    {
        ll n = stoil(num);
        db(num, n);
        string s;
        while (n)
        {
            switch (n % 16)
            {
            case 0:
                s += '0';
                break;
            case 1:
                s += 'I';
                break;
            case 10:
                s += 'A';
                break;
            case 11:
                s += 'B';
                break;
            case 12:
                s += 'C';
                break;
            case 13:
                s += 'D';
                break;
            case 14:
                s += 'E';
                break;
            case 15:
                s += 'F';
                break;
            default:
                return "ERROR";
                break;
            }
            n /= 16;
            db(s, n);
        }
        db(s);
        return s;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    cout << s.toHexspeak("3");
}
#endif