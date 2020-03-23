// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 100000 + 5, MOD = 1000000007;

const int offset = NAX / 2, maxLen = 2001;

bool ab[NAX], ac[NAX], bc[NAX];

class Solution
{
private:
    bool match(char c1, char c2)
    {
        return c1 == '?' || c2 == '?' || c1 == c2;
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        string a, b, c;
        cin >> a >> b >> c;
        int A = a.length();
        int B = b.length();
        int C = c.length();
        for (int i = 0; i < A; i++)
            for (int j = 0; j < B; j++)
                if (!match(a[i], b[j]))
                    ab[i - j + offset] = true;

        for (int i = 0; i < A; i++)
            for (int j = 0; j < C; j++)
                if (!match(a[i], c[j]))
                    ac[i - j + offset] = true;

        for (int i = 0; i < B; i++)
            for (int j = 0; j < C; j++)
                if (!match(b[i], c[j]))
                    bc[i - j + offset] = true;

        int ans = 3 * maxLen;

        for (int startB = -2 * maxLen; startB <= 2 * maxLen; startB++)
            for (int startC = -2 * maxLen; startC <= 2 * maxLen; startC++)
                if (!ab[startB + offset] && !ac[startC + offset] && !bc[startC - startB + offset])
                {
                    int L = min({0, startB, startC});
                    int R = max(A, max(B + startB, C + startC));
                    ans = min(ans, R - L);
                }
        cout << ans << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}