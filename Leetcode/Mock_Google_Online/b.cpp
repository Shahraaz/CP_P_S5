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

struct Rabin_Karp
{
    int maxSize;
    const long long p1 = 805306457, p2 = 29, p3 = 31;
    const int mod1 = 1610612741, mod2 = 2100003221, mod3 = 1e9 + 9;
    vector<long long> p_pow1, p_pow2, p_pow3;
    vector<long long> inv_pow1, inv_pow2, inv_pow3;
    ll expo(ll base, int index, int mod)
    {
        if (index == 0)
            return 1;
        ll temp = expo(base, index / 2, mod);
        temp = (temp * temp) % mod;
        if (index & 1)
            temp = (temp * base) % mod;
        return temp;
    }
    Rabin_Karp(int n)
    {
        maxSize = n + 1;
        p_pow1.resize(maxSize);
        p_pow2.resize(maxSize);
        p_pow3.resize(maxSize);
        inv_pow1.resize(maxSize);
        inv_pow2.resize(maxSize);
        inv_pow3.resize(maxSize);
        p_pow1[0] = p_pow2[0] = p_pow3[0] = 1;
        for (int i = 1; i < (int)p_pow1.size(); i++)
        {
            p_pow1[i] = (p_pow1[i - 1] * p1) % mod1;
            p_pow2[i] = (p_pow2[i - 1] * p2) % mod2;
            p_pow3[i] = (p_pow3[i - 1] * p3) % mod3;
        }
        inv_pow1[maxSize - 1] = expo(p_pow1[maxSize - 1], mod1 - 2, mod1);
        inv_pow2[maxSize - 1] = expo(p_pow2[maxSize - 1], mod2 - 2, mod2);
        inv_pow3[maxSize - 1] = expo(p_pow3[maxSize - 1], mod3 - 2, mod3);
        for (int i = maxSize - 2; i >= 0; --i)
        {
            inv_pow1[i] = (inv_pow1[i + 1] * p1) % mod1;
            inv_pow2[i] = (inv_pow2[i + 1] * p2) % mod2;
            inv_pow3[i] = (inv_pow3[i + 1] * p3) % mod3;
        }
    }
    string s, prefix, suffix;
    vector<pair<long long, pair<long long, long long>>> hashUptoIndex;
    pair<long long, pair<long long, long long>> getHash(int startIndex, int endIndex)
    {
        long long a = (hashUptoIndex[endIndex].f - (startIndex ? hashUptoIndex[startIndex - 1].f : 0) + mod1) % mod1;
        long long b = (hashUptoIndex[endIndex].s.f - (startIndex ? hashUptoIndex[startIndex - 1].s.f : 0) + mod2) % mod2;
        long long c = (hashUptoIndex[endIndex].s.s - (startIndex ? hashUptoIndex[startIndex - 1].s.s : 0) + mod3) % mod3;
        a = (a * inv_pow1[startIndex]) % mod1;
        b = (b * inv_pow2[startIndex]) % mod2;
        c = (c * inv_pow3[startIndex]) % mod3;
        auto ret = make_pair(a, make_pair(b, c));
        return ret;
    }
    int solve(string text)
    {
        int n = text.size();
        hashUptoIndex.resize(n);
        for (int i = 0; i < n; ++i)
        {
            hashUptoIndex[i].f = (((i > 0) ? (hashUptoIndex[i - 1].f) : (0)) + (text[i] - 'a' + 1) * p_pow1[i]) % mod1;
            hashUptoIndex[i].s.f = (((i > 0) ? (hashUptoIndex[i - 1].s.f) : (0)) + (text[i] - 'a' + 1) * p_pow2[i]) % mod2;
            hashUptoIndex[i].s.s = (((i > 0) ? (hashUptoIndex[i - 1].s.s) : (0)) + (text[i] - 'a' + 1) * p_pow3[i]) % mod3;
        }
        return 0;
    }
};

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        Rabin_Karp R(n);
        R.solve(s);
        db(n, R.maxSize);
        for (ll len = 1; len <= (n - 1); ++len)
        {
            if (n % len == 0)
            {
                bool ok = true;
                auto prefhash = R.getHash(0, len - 1);
                for (int i = len; i < n; i += len)
                {
                    auto now = R.getHash(i, i + len - 1);
                    if (prefhash != now)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    return ok;
            }
        }
        return false;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    string str;
    cin >> str;
    cout << s.repeatedSubstringPattern(str) << '\n';
}
#endif
