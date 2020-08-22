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

#define int ll

const int NAX = 2e5 + 5, MOD = 1000000007;

struct Solution
{
    Solution() {}
    void solveCase();
};

struct Player
{
    int idx;
    int rank;
    int prefSum;
    int qSolveCnt;
    Player(int idx, int rank, int prefSum, int qSolveCnt)
    {
        this->idx = idx;
        this->rank = rank;
        this->prefSum = prefSum;
        this->qSolveCnt = qSolveCnt;
    }
    bool operator<(const Player &rhs) const
    {
        if (qSolveCnt == rhs.qSolveCnt)
            return idx < rhs.idx;
        return qSolveCnt < rhs.qSolveCnt;
    }
};

vector<Player> players;

struct EqualGroup
{
    mutable set<int> equalGroupMembers;
    mutable int rank;
    mutable int prefSum;
    mutable int qSolveCnt;
    mutable int lastUpdidx;

    EqualGroup(int rank, int prefSum, int qSolveCnt, int lastUpdidx)
    {
        this->rank = rank;
        this->prefSum = prefSum;
        this->qSolveCnt = qSolveCnt;
        this->lastUpdidx = lastUpdidx;
    }
    void addMember(vector<int> memberIdList, int idx) const
    {
        prefSum += (idx - lastUpdidx) * (rank);
        lastUpdidx = idx;
        for (auto &x : memberIdList)
        {
            players[x].prefSum -= prefSum;
            players[x].rank = rank;
            equalGroupMembers.insert(x);
        }
    }
    bool removeMembers(vector<int> memberIdList, int idx) const
    {
        prefSum += (idx - lastUpdidx) * (rank);
        rank += memberIdList.size();
        for (auto &x : memberIdList)
        {
            players[x].prefSum += prefSum;
            players[x].qSolveCnt++;
            // players[x].rank = rank;
            equalGroupMembers.erase(x);
        }
        lastUpdidx = idx;
        return equalGroupMembers.empty();
    }
    bool operator<(const EqualGroup &rhs) const
    {
        return qSolveCnt < rhs.qSolveCnt;
    }
};

void Solution::solveCase()
{
    set<pair<int, EqualGroup>> rankList;
    EqualGroup E(0, 0, 0, 0);
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        Player p(i, 0, 0, 0);
        players.pb(p);
        E.addMember({i}, 0);
    }
    rankList.insert({0, E});
    for (int i = 0; i < w; i++)
    {
        int k;
        cin >> k;
        map<int, vector<int>> mp;
        for (size_t j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            --x;
            mp[players[x].qSolveCnt].pb(x);
        }
        for (auto x : mp)
        {
            auto it = rankList.lower_bound({x.f, EqualGroup(0, 0, 0, 0)});
            if (it != rankList.end())
            {
                int prevRank = (it->s).rank;
                if ((it->s).removeMembers(x.s, i))
                    rankList.erase(it);
                it = rankList.lower_bound({x.f + 1, EqualGroup(0, 0, 0, 0)});
                if (it != rankList.end() && ((it->s).qSolveCnt == (x.f + 1)))
                    (it->s).addMember(x.s, i);
                else
                {
                    EqualGroup E(prevRank, 0, x.f + 1, i);
                    E.addMember(x.s, i);
                    rankList.insert({x.f + 1, E});
                }
            }
        }
        db(i);
        db(mp);
#ifdef LOCAL
        for (auto &x : rankList)
            db(x.f, x.s.rank, x.s.equalGroupMembers);
#endif
    }
    vector<int> prevRank(n);
    for (auto &x : rankList)
    {
        vector<int> temp;
        for (auto &y : (x.s).equalGroupMembers)
        {
            temp.pb(y);
            // db(y);
            prevRank[y] = x.s.rank;
            // prevRank[y] = players[y].prefSum
        }
        x.s.removeMembers(temp, w - 1);
        for (auto &y : temp)
        {
            db(y, players[y].prefSum);
            db(prevRank[y]);
            prevRank[y] += players[y].prefSum;
        }
    }
    for (auto &x : prevRank)
    {
        cout << fixed << setprecision(9);
        cout << ((long double)x / w + 1) << '\n';
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
