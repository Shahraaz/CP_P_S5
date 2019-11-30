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

const int nax = 2e5 + 10;

class Solution
{
public:
    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved)
    {
        vector<vector<int>> ret;
        for (auto i : intervals)
        {
            if (i[0] <= toBeRemoved[0] && toBeRemoved[0] <= i[1] && i[1] <= toBeRemoved[1])
            {
                cout << "A " << i[0] << ' ' << i[1] << '\n';
                if (toBeRemoved[0] - i[0] > 0)
                    ret.pb({i[0], toBeRemoved[0]});
            }
            else if (i[0] >= toBeRemoved[0] && toBeRemoved[1] >= i[1])
            {
                cout << "B " << i[0] << ' ' << i[1] << '\n';
            }
            else if (i[0] <= toBeRemoved[0] && toBeRemoved[1] <= i[1])
            {
                cout << "C " << i[0] << ' ' << i[1] << '\n';
                if (toBeRemoved[0] - i[0] > 0)
                    ret.pb({i[0], toBeRemoved[0]});
                if (i[1] - toBeRemoved[1] > 0)
                    ret.pb({toBeRemoved[1], i[1]});
            }
            else if (toBeRemoved[0] <= i[0] && i[0]<=toBeRemoved[1] && toBeRemoved[1] <= i[1])
            {
                cout << "D " << i[0] << ' ' << i[1] << '\n';
                if (i[1] - toBeRemoved[1] > 0)
                    ret.pb({toBeRemoved[1], i[1]});
            }
            else
                ret.pb(i);
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        // for (auto elem : ret)
        //     cout << elem[0] << ' ' << elem[1] << '\n';
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
}
#endif