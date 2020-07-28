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
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if(count(all(wordList),endWord) == 0)
            return 0;
        wordList.pb(beginWord);
        wordList.pb(endWord);
        int n = wordList.size();
        vector<vector<int>> adj(n);
        for (size_t i = 0; i < n; i++)
            for (size_t j = i + 1; j < n; j++)
            {
                int diff = 0;
                for (size_t k = 0; k < beginWord.size(); k++)
                    diff += wordList[i][k] != wordList[j][k];
                if (diff == 1)
                {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
            }
        vector<int> dist(n, -1);
        queue<int> Q;
        dist[n - 2] = 0;
        Q.push(n - 2);
        while (Q.size())
        {
            auto top = Q.front();
            // cout << top << ' ' << dist[top] << '\n';
            Q.pop();
            for (auto &x : adj[top])
                if (dist[x] == -1)
                {
                    dist[x] = dist[top] + 1;
                    Q.push(x);
                }
        }
        return dist[n - 1] + 1;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif