#include <bits/stdc++.h>
using namespace std;
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
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        vector<bool> vis(n);
        queue<pair<int, int>> Q;
        Q.push({id, 0});
        vis[id] = true;
        vector<string> ret;
        map<string, int> m;
        vector<pair<int, string>> temp;
        while (!Q.empty())
        {
            auto top = Q.front();
            Q.pop();
            if (top.s == level)
                for (auto video : watchedVideos[top.f])
                    m[video]++;
            for (auto Friend : friends[top.f])
            {
                if (!vis[Friend])
                {
                    vis[Friend] = true;
                    Q.push({Friend, top.s + 1});
                }
            }
        }
        for (auto elem : m)
            temp.pb({elem.s, elem.f});
        sort(temp.begin(), temp.end());
        for (auto elem : temp)
            ret.pb(elem.s);
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
}
#endif
