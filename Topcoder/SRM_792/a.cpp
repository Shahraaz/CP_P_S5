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

class TwoRobots
{
public:
    int move(vector<string> plan)
    {
        int n = plan.size();
        int m = plan[0].size();
        pair<int, int> startA, endA;
        pair<int, int> startB, endB;
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
            {
                if (plan[i][j] == 'A')
                    startA.f = i, startA.s = j;
                else if (plan[i][j] == 'a')
                    endA.f = i, endA.s = j;

                if (plan[i][j] == 'B')
                    startB.f = i, startB.s = j;
                else if (plan[i][j] == 'b')
                    endB.f = i, endB.s = j;
            }
        using point = pair<int, int>;
        map<pair<point, point>, int> dist;
        // map<pair<point, point>, pair<point, point>> prev;
        dist[make_pair(startA, startB)] = 0;
        // prev[make_pair(startA, startB)] = make_pair(startA, startB);
        queue<pair<point, point>> Q;
        Q.push({startA, startB});
        int a[] = {0, 0, 1, -1};
        int b[] = {1, -1, 0, 0};
        while (Q.size())
        {
            auto front = Q.front();
            // db(front, dist[front]);
            // cout << front.f.f << ' ' << front.f.s << ' ';
            // cout << front.s.f << ' ' << front.s.s << ' ';
            // cout << dist[front] << '\n';
            if (front.f == endA && front.s == endB)
                return dist[front];
            Q.pop();
            for (size_t i = 0; i < 4; i++)
            {
                int x1 = front.f.f + a[i];
                int y1 = front.f.s + b[i];
                if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m)
                    if (plan[x1][y1] != '#')
                        for (size_t j = 0; j < 4; j++)
                        {
                            int x2 = front.s.f + a[j];
                            int y2 = front.s.s + b[j];
                            if (x1 == x2 && y1 == y2)
                                continue;
                            if (point(x1, y1) == front.s && point(x2, y2) == front.f)
                                continue;
                            if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m)
                                if (plan[x2][y2] != '#')
                                    if (dist.find(make_pair(point(x1, y1), point(x2, y2))) == dist.end())
                                    {
                                        dist[make_pair(point(x1, y1), point(x2, y2))] = dist[front] + 1;
                                        Q.push(make_pair(point(x1, y1), point(x2, y2)));
                                    }
                        }
            }
        }
        return -1;
    }
};
