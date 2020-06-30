// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        /*
        1 2 3 4 5 6
        1 2 4 3 5 6
        1 4 5 2 3 6
        */
        /*
        8
        0 1 2 3 4 5 6 7
        0 1 2 4 3 5 6 7
        0 1 4 5 2 3 6 7
        0 4 5 6 1 2 3 7

        1 prev1................n
        1 prev2................n
        1 prev.................n
        1 prev.................n
        1 prevn-1................n
        1 n/2 n/2+1 n-1 2 3 4 n

        1 2 3 4 5 6 7 8

        1 6 3 8 5 2 7 4

        5 2 3 8 1 6 7 4

        2 4 6 8
        1 5 6 2

        1 2 3 4 5 6 7 8 9 10
        6 2 3 4 5 1 7 8 9 10

        1:   
        2:  3 4 5  
        3:  2 4 5  
        4:  2 3 5  
        5:  2 3 4  
        6:          
        7:          8 9 10 
        8:          7 9 10 
        9:          7 8 10 
        10:         7 8 9

        8  1 0 0 0 3
        10 1 0 1 0 4
        12 1 1 0 0 5/4
        14 1 1 1 0 6/4
        16 1 0 0 0 0 4

        1 2 3 4 5 6 7 8       9 10 11 12 13 14 15 16
        1 10 3 12 5 14 7 16   9 2 11 4 13 6 15 8
        1 10 11 4 5 14 15 8   9 2 3 12 13 6 7 16
        1 10 11 4 13 6 7 16   9 2 3 12 5 14 15 8

        12 1 1 0 0

        1 2 3 4 5 6         7 8 9 10 11 12 
        1 8 3 10 5 12       7 2 9 4 11 6 
        7 2 3 10 11 6       1 8 9 4 5 12 
        1 8 9 4 11 6        7 2 3 10 5 12 
        
        1 2 3 4 5 6 7     8 9 10 11 12 13 14
        8 2 10 4 12 6 14  1 9 3 11 5 13 7
        1 9 10 4 5 13 14  8 2 3 11 12 6 7
        2 3 11 12 5 13 14  8 1 9 10 4 6 7
                
        */
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<set<int>> adj(n + 1);
        for (size_t i = 0; i < k; i++)
        {
            vector<int> a(n);
            for (size_t j = 0; j < n; j++)
                cin >> a[j];
            for (size_t j = 0; j < n / 2; j++)
                for (size_t k = n / 2; k < n; k++)
                {
                    if (a[j] == a[k])
                        continue;
                    adj[a[j]].insert(a[k]);
                    adj[a[k]].insert(a[j]);
                }
            db(i, a)
        }
        for (size_t i = 1; i <= n; i++)
            cout << adj[i].size() << ' ';
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
