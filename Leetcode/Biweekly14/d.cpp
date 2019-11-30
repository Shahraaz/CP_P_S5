#ifdef LOCAL
#include <bits/stdc++.h>
using namespace std;
#endif
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int NAX = 2e5 + 10;
/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */
int cnt = 0;
class Solution
{

    int recurse(Sea sea, vector<int> topRight, vector<int> bottomLeft, bool step = 0)
    {
        int area = (topRight[1] - bottomLeft[1]) * (topRight[0] - bottomLeft[0]);
        if (area < 0)
            return 0;
        if (area == 0)
            return sea.hasShips(topRight, bottomLeft);
        if (area == 1)
        {
            return sea.hasShips({topRight[0], topRight[1]}, {topRight[0], topRight[1]}) +
                   sea.hasShips({bottomLeft[0], topRight[1]}, {bottomLeft[0], topRight[1]}) +
                   sea.hasShips({topRight[0], bottomLeft[1]}, {topRight[0], bottomLeft[1]}) +
                   sea.hasShips({bottomLeft[0], bottomLeft[1]}, {bottomLeft[0], bottomLeft[1]});
        }
        if (sea.hasShips(topRight, bottomLeft))
        {
            if (step)
            {
                vector<int> MTop;
                MTop.pb((topRight[0] + bottomLeft[0] + 1) / 2);
                MTop.pb((topRight[1]));
                vector<int> MMTop;
                MMTop.pb((topRight[0] + bottomLeft[0] + 1) / 2 + 1);
                MMTop.pb((bottomLeft[1]));
                return recurse(sea, topRight, MMTop, !step) + recurse(sea, MTop, bottomLeft, !step);
            }
            else
            {
                vector<int> MTop;
                MTop.pb((topRight[0]));
                MTop.pb((topRight[1] + bottomLeft[1] + 1) / 2);
                vector<int> MMTop;
                MMTop.pb((bottomLeft[0]));
                MMTop.pb((topRight[1] + bottomLeft[1] + 1) / 2 + 1);
                return recurse(sea, topRight, MMTop, !step) + recurse(sea, MTop, bottomLeft, !step);
            }
        }
        return 0;
    }

public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft)
    {
        return recurse(sea, topRight, bottomLeft);
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
}
#endif