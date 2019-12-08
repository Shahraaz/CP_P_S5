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
    vector<vector<int>> groupThePeople(vector<int> groupSizes)
    {
        int n = groupSizes.size();
        db("here");
        vector<queue<int>> indices(n + 1);
        for (int i = 0; i < n; ++i)
            indices[groupSizes[i]].push(i);
        db("here");
        vector<vector<int>> ret;
        db("here");
        for (int i = 1; i <= n; ++i)
        {
            while (indices[i].size())
            {
                vector<int> temp;
                for (int j = 0; j < i; ++j)
                {
                    temp.pb(indices[i].front());
                    indices[i].pop();
                }
                ret.pb(temp);
            }
        }
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    auto ret = s.groupThePeople({3, 3, 3, 3, 3, 1, 3});
    for (auto elem : ret)
        pc(elem);
}
#endif