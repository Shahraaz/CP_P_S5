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

void solveCase()
{
    string s;
    cin >> s;
    pair<ll, ll> curr;
    vector<pair<ll, ll>> blocks;
    int ctr = 2;
    auto cat = [&](int i) -> int {
        return (s[i] == 'L' || s[i] == 'R');
    };
    vector<pair<ll, ll>> prevPoses;
    prevPoses.pb(curr);
    int n = s.size();
    if (n > 2 && s[n - 1] == s[n - 3] && cat(n - 1) == cat(n - 2))
    {
        cout << "impossible\n";
        return;
    }
    for (size_t i = 0; i < s.size(); i++)
    {
        db(i, s[i], cat(i));
        if (i > 0 && s[i] == s[i - 1])
        {
            cout << "impossible\n";
            return;
        }
        if (i >= 2 && s[i] == s[i - 2] && cat(i) == cat(i - 1))
        {
            curr = prevPoses[i - 1];
        }
        else if (s[i] == 'L')
        {
            curr.f = curr.f - ctr;
            ctr *= 2;
            blocks.pb({curr.f - 1, curr.s});
        }
        else if (s[i] == 'R')
        {
            curr.f = curr.f + ctr;
            ctr *= 2;
            blocks.pb({curr.f + 1, curr.s});
        }
        else if (s[i] == 'U')
        {
            curr.s = curr.s + ctr;
            ctr *= 2;
            blocks.pb({curr.f, curr.s + 1});
        }
        else if (s[i] == 'D')
        {
            curr.s = curr.s - ctr;
            ctr *= 2;
            blocks.pb({curr.f, curr.s - 1});
        }
        prevPoses.pb(curr);
    }
    // for (auto &x : prevPoses)
    // {
    //     cout << x.f << ' ' << x.s << '\n';
    // }
    db("blocks");
    db(blocks);
    db(prevPoses);
    // cout << blocks.back().f << ' ' << blocks.back().s << '\n';
    // cout << blocks.size() - 1 << '\n';
    cout << -prevPoses.back().f << ' ' << -prevPoses.back().s << '\n';

    for (size_t i = 0; i < blocks.size(); i++)
    {
        blocks[i].f -= prevPoses.back().f;
        blocks[i].s -= prevPoses.back().s;
    }
    cout << blocks.size() << '\n';
    for (size_t i = 0; i < blocks.size(); i++)
    {
        cout << blocks[i].f << ' ' << blocks[i].s << '\n';
    }
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
    {
        solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
