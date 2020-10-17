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
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> events;
        for (int i = 0; i < arrival.size(); i++)
            events.push({arrival[i], i % k});
        vector<int> busiest;
        vector<int> req(k);
        set<int> free;
        for (size_t i = 0; i < k; i++)
            free.insert(i);
        int onLoad = 0;
        while (events.size())
        {
            auto it = events.top();
            events.pop();
            if (it.s >= 0) // new Load
            {
                if (onLoad == k)
                    continue; //drop
                onLoad++;
                int lptr = it.s % k;
                auto server = free.lower_bound(lptr);
                if (server == free.end())
                    server = free.lower_bound(0);
                req[*server]++;
                events.push({arrival[it.s] + load[it.s], -*server - 1});
                free.erase(server);
            }
            else
            {
                free.insert(-it.s + 1);
                onLoad--;
            }
        }
        auto maxi = *max_element(all(req));
        for (size_t i = 0; i < k; i++)
            if (req[i] == maxi)
                busiest.pb(i);
        return busiest;
    }
};