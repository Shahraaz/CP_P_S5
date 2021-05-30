#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 3e5 + 5, MOD = 1000000007;

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
using ll = long long;

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

void solveCase()
{
    string str;
    cin >> str;
    for (auto &x : str)
        x = (x - 'A') + 'a';
    R.prepareString(str);
    int low = 1, high = str.size(), ans = high;
    auto check = [&](int len) -> int
    {
        map<int, int> mp;
        for (int i = 0; i + len - 1 < str.size(); i++)
        {
            auto h = R.getHash(i, i + len - 1);
            auto it = mp.find(h);
            if (it != mp.end())
                it->second = MOD;
            else
                mp[h] = i;
        }
        int mini = MOD;
        for (auto &x : mp)
            if (x.second < MOD)
                mini = min(mini, x.second);
        return mini;
    };
    int idx = MOD;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid) != MOD)
            ans = mid, high = mid - 1;
        else
            low = mid + 1;
    }
    idx = check(ans);
    auto res_str = str.substr(idx, ans);
    for (auto &c : res_str)
    {
        c = c - 'a' + 'A';
    }
    cout << res_str << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}