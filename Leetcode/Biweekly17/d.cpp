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

struct Rabin_Karp
{
    const int maxSize = 2e3 + 10;
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
    Rabin_Karp()
    {
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
    int solve(string pattern, string text)
    {
        if (text.size() < pattern.size())
            return 0;
        int patternSize = pattern.size();
        int textSize = text.size();
        int cnt = 0;
        pair<ll, pair<ll, ll>> hashPattern;
        for (auto c : pattern)
        {
            hashPattern.f = (hashPattern.f * p1 + c - 'a' + 1) % mod1;
            hashPattern.s.f = (hashPattern.s.f * p2 + c - 'a' + 1) % mod2;
            hashPattern.s.s = (hashPattern.s.s * p3 + c - 'a' + 1) % mod3;
        }
        pair<ll, pair<ll, ll>> currentTextHash;
        for (int i = 0; i < patternSize; ++i)
        {
            currentTextHash.f = (currentTextHash.f * p1 + text[i] - 'a' + 1) % mod1;
            currentTextHash.s.f = (currentTextHash.s.f * p2 + text[i] - 'a' + 1) % mod2;
            currentTextHash.s.s = (currentTextHash.s.s * p3 + text[i] - 'a' + 1) % mod3;
        }
        cnt += currentTextHash == hashPattern;
        for (int i = patternSize; i < textSize; ++i)
        {
            currentTextHash.f = (currentTextHash.f - ((text[i - patternSize] - 'a' + 1) * p_pow1[patternSize - 1]) % mod1 + mod1) % mod1;
            currentTextHash.s.f = (currentTextHash.s.f - ((text[i - patternSize] - 'a' + 1) * p_pow2[patternSize - 1]) % mod2 + mod2) % mod2;
            currentTextHash.s.s = (currentTextHash.s.s - ((text[i - patternSize] - 'a' + 1) * p_pow3[patternSize - 1]) % mod3 + mod3) % mod3;

            currentTextHash.f = (currentTextHash.f * p_pow1[1]) % mod1;
            currentTextHash.s.f = (currentTextHash.s.f * p_pow2[1]) % mod2;
            currentTextHash.s.s = (currentTextHash.s.s * p_pow3[1]) % mod3;

            currentTextHash.f = (currentTextHash.f + (text[i] - 'a' + 1)) % mod1;
            currentTextHash.s.f = (currentTextHash.s.f + (text[i] - 'a' + 1)) % mod2;
            currentTextHash.s.s = (currentTextHash.s.s + (text[i] - 'a' + 1)) % mod3;

            cnt += currentTextHash == hashPattern;
            // db(i, currentTextHash, hashPattern);
        }
        return cnt;
    }
    void prepareString(string text)
    {
        int n = text.size();
        hashUptoIndex.resize(n);
        for (int i = 0; i < n; ++i)
        {
            hashUptoIndex[i].f = (((i > 0) ? (hashUptoIndex[i - 1].f) : (0)) + (text[i] - 'a' + 1) * p_pow1[i]) % mod1;
            hashUptoIndex[i].s.f = (((i > 0) ? (hashUptoIndex[i - 1].s.f) : (0)) + (text[i] - 'a' + 1) * p_pow2[i]) % mod2;
            hashUptoIndex[i].s.s = (((i > 0) ? (hashUptoIndex[i - 1].s.s) : (0)) + (text[i] - 'a' + 1) * p_pow3[i]) % mod3;
        }
    }
};

Rabin_Karp R;

class Solution
{
public:
    int distinctEchoSubstrings(string text)
    {
        R.prepareString(text);
        int n = text.length();
        set<pair<ll, pair<ll, ll>>> somename;
        for (int len = 1; len < n; len++)
        {
            for (int i = 0; (i + 2 * len) <= n; i++)
            {
                auto temp = R.getHash(i,i+len-1);
                if (temp == R.getHash(i + len, i + 2 * len - 1))
                    somename.insert(temp);
            }
        }

        return somename.size();
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