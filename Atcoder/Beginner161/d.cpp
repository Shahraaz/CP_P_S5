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

const int NAX = 2e5 + 5, MOD = 1000000007;

ll numOfLunLunWithLenlandStartx[20][10];
class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int k;
        cin >> k;
        for (size_t i = 0; i < 10; i++)
            numOfLunLunWithLenlandStartx[1][i] = 1;
        for (int i = 2; i < 20; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                numOfLunLunWithLenlandStartx[i][j] += numOfLunLunWithLenlandStartx[i - 1][j];
                if (j > 0)
                    numOfLunLunWithLenlandStartx[i][j] += numOfLunLunWithLenlandStartx[i - 1][j - 1];
                if (j < 9)
                    numOfLunLunWithLenlandStartx[i][j] += numOfLunLunWithLenlandStartx[i - 1][j + 1];
                db(i, j, numOfLunLunWithLenlandStartx[i][j]);
            }
        }
        ll currCnt = 0;
        for (int len = 1; len < 20; len++)
        {
            for (size_t firstDig = 1; firstDig < 10; firstDig++)
            {
                currCnt += numOfLunLunWithLenlandStartx[len][firstDig];
                db(len, firstDig, currCnt);
                if (currCnt >= k)
                {
                    int curr = firstDig;
                    string str;
                    while (len--)
                    {
                        // cout << curr;
                        str += curr + '0';
                        db(currCnt, curr);
                        if (len >= 0)
                            for (auto &x : {curr + 1, curr, curr - 1})
                            {
                                db(x, len);
                                if (x >= 0 && x < 10)
                                {
                                    db(currCnt, len, x, numOfLunLunWithLenlandStartx[len][x]);
                                    if (currCnt - numOfLunLunWithLenlandStartx[len][x] >= k)
                                    {
                                        curr = x;
                                        currCnt -= numOfLunLunWithLenlandStartx[len][x];
                                    }
                                    else
                                        break;
                                }
                            }
                        // len--;
                    }
                    cout << str << '\n';
                    return;
                }
            }
        }
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