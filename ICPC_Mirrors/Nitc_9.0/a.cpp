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

struct Solution
{
    Solution() {}
    void solveCase();
};

struct Player
{
    ll id;
    ll cummSum;
    int rank;
    int qCnt;
    Player(ll id, ll cummSum)
    {
        this->id = id;
        this->cummSum = cummSum;
        rank = 1;
        qCnt = 0;
    }
    bool operator<(const Player &rhs) const
    {
        if (qCnt == rhs.qCnt)
            return id < rhs.id;
        return qCnt < rhs.qCnt;
    }
};

ostream &operator<<(ostream &ou, const Player &p)
{
    ou << "player id " << p.id << " rank " << p.rank << " currSum " << p.cummSum << " qcnt " << p.qCnt;
    return ou;
}

struct Team
{
    ll prevupdateIdx;
    ll overSum;
    ll rank;
    int qCnt;
    set<Player *> currMembers;
    Team(ll prevupdateIdx, ll overSum, ll rank, int QCnt = 0)
    {
        this->prevupdateIdx = prevupdateIdx;
        this->overSum = overSum;
        this->rank = rank;
        this->qCnt = QCnt;
    }
    void addMember(Player *p, int idx)
    {
        p->cummSum -= (prevupdateIdx - idx) * rank;
        p->rank = rank;
        p->qCnt = qCnt;
        currMembers.insert(p);
    }
    void removeMember(Player *p, int idx)
    {
        p->cummSum += (prevupdateIdx - idx) * rank;
        // p->rank = rank;
        currMembers.erase(p);
        overSum += (prevupdateIdx - idx) * rank;
        if (prevupdateIdx != idx)
            rank++;
        prevupdateIdx = idx;
    }
    bool operator<(const Team &rhs) const
    {
        return qCnt > rhs.qCnt;
    }
};

ostream &operator<<(ostream &ou, const Team &p)
{
    ou << "team prevupdateIdx " << p.prevupdateIdx << " rank " << p.rank << " overSum " << p.overSum << ' ' << "Qcnt " << p.qCnt << ' ';
    for (auto &x : p.currMembers)
        ou << *x << ' ';
    return ou;
}

void Solution::solveCase()
{
    int n, w;
    cin >> n >> w;
    vector<Player *> P(n);
    for (size_t i = 0; i < n; i++)
    {
        P[i] = new Player(i, 0);
    }
    set<struct Team> rankedList;
    Team everyone(-1, 0, 1);
    for (auto &x : P)
        everyone.addMember(x, -1);
    rankedList.insert(everyone);
    for (size_t i = 0; i < w; i++)
    {
        int k;
        cin >> k;
        set<pair<int, Player *>> vv;
        for (size_t j = 0; j < k; j++)
        {
            int c;
            cin >> c;
            --c;
            vv.insert({P[c]->rank, P[c]});
        }
        // db(vv);
        // for (auto &x : vv)
        // {
        //     cout << x.f << ' ' << *(x.s) << '\n';
        // }
        db("before");
        for (auto &x : rankedList)
        {
            cout << x.qCnt << ' ' << x.rank << '\n';
            for (auto &y : x.currMembers)
            {
                cout << *y << '\n';
            }
            // cout << '\n';
        }
        for (auto &x : vv)
        {
            auto it = rankedList.lower_bound(Team(0, 0, (x.s)->qCnt));
            if (it != rankedList.end())
            {
                auto temp = *it;
                rankedList.erase(it);
                // temp.removeMember()
                temp.removeMember(P[x.s->id], i);
                rankedList.insert(temp);
            }
            it = rankedList.lower_bound(Team(0, 0, (x.s)->qCnt + 1));
            if (it != rankedList.end() && (it->qCnt) == (1 + (x.s)->qCnt))
            {
                auto temp = *it;
                rankedList.erase(it);
                // temp.removeMember()
                temp.addMember(P[x.s->id], i);
                rankedList.insert(temp);
            }
            else
            {
                Team temp = Team(i, 0, (x.s)->rank, 1 + (x.s)->qCnt);
                temp.addMember(P[x.s->id], i);
                rankedList.insert(temp);
            }
        }
        db("after");
        for (auto &x : rankedList)
        {
            cout << x.qCnt << ' ' << x.rank << '\n';
            for (auto &y : x.currMembers)
            {
                cout << *y << '\n';
            }
            // cout << '\n';
        }
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
