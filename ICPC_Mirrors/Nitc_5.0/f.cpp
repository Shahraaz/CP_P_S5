// Optimise
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = int;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 2e5 + 5, MOD = 1000000007;

struct Hash_RabinKarp
{
    const int maxSize = 2e5 + 10;
    const int p1 = 805306457, p2 = 29, p3 = 31;
    const int mod1 = 1610612741, mod2 = 2100003221, mod3 = 1e9 + 9;
    vector<int> p_pow1, p_pow2, p_pow3;
    vector<int> inv_pow1, inv_pow2, inv_pow3;
    ll expo(ll base, int index, int mod)
    {
        if (index == 0)
            return 1;
        ll temp = expo(base, index / 2, mod);
        temp = (1LL * temp * temp) % mod;
        if (index & 1)
            temp = (1LL * temp * base) % mod;
        return temp;
    }
    Hash_RabinKarp()
    {
        p_pow1.resize(maxSize);
        p_pow2.resize(maxSize);
        // p_pow3.resize(maxSize);
        inv_pow1.resize(maxSize);
        inv_pow2.resize(maxSize);
        // inv_pow3.resize(maxSize);
        p_pow1[0] = p_pow2[0] = 1;
        // p_pow1[0] = p_pow2[0] = p_pow3[0] = 1;
        for (int i = 1; i < (int)p_pow1.size(); i++)
        {
            p_pow1[i] = (1LL * p_pow1[i - 1] * p1) % mod1;
            p_pow2[i] = (1LL * p_pow2[i - 1] * p2) % mod2;
            // p_pow3[i] = (1LL * p_pow3[i - 1] * p3) % mod3;
        }
        inv_pow1[maxSize - 1] = expo(p_pow1[maxSize - 1], mod1 - 2, mod1);
        inv_pow2[maxSize - 1] = expo(p_pow2[maxSize - 1], mod2 - 2, mod2);
        // inv_pow3[maxSize - 1] = expo(p_pow3[maxSize - 1], mod3 - 2, mod3);
        for (int i = maxSize - 2; i >= 0; --i)
        {
            inv_pow1[i] = (1LL * inv_pow1[i + 1] * p1) % mod1;
            inv_pow2[i] = (1LL * inv_pow2[i + 1] * p2) % mod2;
            // inv_pow3[i] = (1LL * inv_pow3[i + 1] * p3) % mod3;
        }
    }
} hashTables;

// #define hash pair<int, pair<int, int>>
#define hash int
// struct Rabin_Karp
// {
//     int valLen;
//     Rabin_Karp()
//     {
//         valLen = 0;
//     }
//     Rabin_Karp(string str)
//     {
//         prepareString(str);
//     }
//     vector<hash> hashUptoIndex;
//     hash getHash(int startIndex, int endIndex)
//     {
//         if (startIndex > endIndex || startIndex < 0 || startIndex >= valLen || endIndex < 0 || endIndex >= valLen)
//             return {0, {0, 0}};
//         int a = (1LL * hashUptoIndex[endIndex].f - (startIndex ? hashUptoIndex[startIndex - 1].f * 1LL : 0LL) + hashTables.mod1) % hashTables.mod1;
//         int b = (1LL * hashUptoIndex[endIndex].s.f - (startIndex ? hashUptoIndex[startIndex - 1].s.f * 1LL : 0LL) + hashTables.mod2) % hashTables.mod2;
//         int c = 0;
//         // int c = (1LL * hashUptoIndex[endIndex].s.s - (startIndex ? hashUptoIndex[startIndex - 1].s.s * 1LL : 0LL) + hashTables.mod3) % hashTables.mod3;
//         a = (a * 1LL * hashTables.inv_pow1[startIndex]) % hashTables.mod1;
//         b = (b * 1LL * hashTables.inv_pow2[startIndex]) % hashTables.mod2;
//         // c = (c * 1LL * hashTables.inv_pow3[startIndex]) % hashTables.mod3;
//         auto ret = make_pair(a, make_pair(b, c));
//         return ret;
//     }
//     void prepareString(string text)
//     {
//         int n = text.size();
//         valLen = n;
//         hashUptoIndex.resize(n);
//         for (int i = 0; i < n; ++i)
//         {
//             hashUptoIndex[i].f = (((i > 0) ? (hashUptoIndex[i - 1].f * 1LL) : (0LL)) + (text[i] - 'a' + 1LL) * hashTables.p_pow1[i]) % hashTables.mod1;
//             hashUptoIndex[i].s.f = (((i > 0) ? (hashUptoIndex[i - 1].s.f * 1LL) : (0LL)) + (text[i] - 'a' + 1LL) * hashTables.p_pow2[i]) % hashTables.mod2;
//             // hashUptoIndex[i].s.s = (((i > 0) ? (hashUptoIndex[i - 1].s.s * 1LL) : (0LL)) + (text[i] - 'a' + 1LL) * hashTables.p_pow3[i]) % hashTables.mod3;
//             hashUptoIndex[i].s.s = 0;
//         }
//     }
// };

const int p = 331;
int hashs[NAX];
int pows[NAX];
struct Rabin_Karp
{
    int valLen;
    Rabin_Karp()
    {
        pows[0] = 1;
        for (int i = 1; i < NAX; i++)
            pows[i] = (pows[i - 1] * 1LL * p) % MOD;
    }
    Rabin_Karp(string str)
    {
        prepareString(str);
    }
    // vector<hash> hashUptoIndex;
    int getHash(int l, int r)
    {
        return ((hashs[r + 1] - (hashs[l] * 1LL * pows[r - l + 1]) % MOD) + MOD) % MOD;
    }
    void prepareString(string s)
    {
        for (int i = 0; i < s.length(); i++)
            hashs[i + 1] = (hashs[i] * 1LL * p + s[i]) % MOD;
        // int n = text.size();
        // valLen = n;
        // hashUptoIndex.resize(n);
        // for (int i = 0; i < n; ++i)
        // {
        //     hashUptoIndex[i].f = (((i > 0) ? (hashUptoIndex[i - 1].f * 1LL) : (0LL)) + (text[i] - 'a' + 1LL) * hashTables.p_pow1[i]) % hashTables.mod1;
        //     hashUptoIndex[i].s.f = (((i > 0) ? (hashUptoIndex[i - 1].s.f * 1LL) : (0LL)) + (text[i] - 'a' + 1LL) * hashTables.p_pow2[i]) % hashTables.mod2;
        //     // hashUptoIndex[i].s.s = (((i > 0) ? (hashUptoIndex[i - 1].s.s * 1LL) : (0LL)) + (text[i] - 'a' + 1LL) * hashTables.p_pow3[i]) % hashTables.mod3;
        //     hashUptoIndex[i].s.s = 0;
        // }
    }
};

Rabin_Karp R;
bool dp[NAX];
string inp_strs[NAX];
set<hash> prev_hashes[(NAX)];

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        /*
            len(lens) < sqrt(2e5)

            str[n];
            for n - 1 to 0:
                for l in lens:
                    curr_hash = str.hash(i,l)
                    if prev_hashes.count(curr_hash) :
                        if dp[i+len]:
                            dp[i] = true;
                            break
            if not dp[0]:
                res++
        */
        int n;
        cin >> n;
        // set<hash> ;
        set<int> lens;
        for (auto &x : inp_strs)
        {
            cin >> x;
            R.prepareString(x);
            // lens.insert(x.length());
            // prev_hashes[x.length()].insert(R.getHash(0, x.length() - 1));
        }
        sort(inp_strs, inp_strs + n, [](string &a, string &b) -> bool {
            return a.length() < b.length();
        });
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            dp[inp_strs[i].size()] = true;
            R.prepareString(inp_strs[i]);
            for (int j = inp_strs[i].size() - 1; j >= 0; j--)
            {
                dp[j] = false;
                for (auto &l : lens)
                {
                    if (j + l <= inp_strs[i].size())
                    {
                        if (dp[j + l])
                        {
                            auto curr_hash = R.getHash(j, j + l - 1);
                            if (prev_hashes[l].find(curr_hash) != prev_hashes[l].end())
                            {
                                dp[j] = true;
                                break;
                            }
                        }
                    }
                    else
                        break;
                }
            }
            db(inp_strs[i]);
#ifdef LOCAL
            cout << inp_strs[i].size() << '\n';
            for (size_t j = 0; j < inp_strs[i].size(); j++)
            {
                cout << dp[j] << ' ';
            }
            cout << '\n';
#endif
            if (!dp[0])
                res++;
            prev_hashes[inp_strs[i].size()].insert(R.getHash(0, inp_strs[i].size() - 1));
            lens.insert(inp_strs[i].size());
        }
        cout << res << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
