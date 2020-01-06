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
public:
    string freqAlphabets(string s)
    {
        string ret;
        int cnt = 0;
        string prev;
        reverse(s.begin(), s.end());
        bool type1 = false;
        int encode = 0;
        vector<char> okoko;
        for (auto c : s)
        {
            if (c == '#')
            {
                cnt = 2;
                type1 = true;
            }
            else if (type1)
            {
                if (cnt == 2)
                {
                    encode = (c - '0');
                    cnt--;
                }
                else if (cnt == 1)
                {
                    encode += (c - '0') * 10;
                    type1 = false;
                    okoko.pb(encode + 'a' - 1);
                    cnt = 0;
                }
            }
            else
            {
                okoko.pb(c - '0' + 'a' - 1);
            }
        }
        reverse((okoko).begin(), okoko.end());
        for (auto c : okoko)
            ret += c;
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.freqAlphabets(str);
}
#endif
