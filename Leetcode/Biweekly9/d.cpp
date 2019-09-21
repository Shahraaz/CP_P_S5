#ifdef WIN32
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

int dp[1001][2048];
class Solution
{
    vector<int> Block;
    int split;
    int solve(int rear, int cnt)
    {
        if (rear == 0)
            return 0;
        if (cnt == 0)
            return mod;
        int &ret = dp[rear][cnt];
        if (ret >= 0)
            return ret;
        ret = 0;
        if (rear <= cnt)
            return max(solve(rear - 1, cnt - 1), Block[rear - 1]);
        ret = max(solve(rear - 1, cnt - 1), Block[rear - 1]);
        ret = min(ret, split + solve(rear, cnt * 2));
        return ret;
    }

public:
    int minBuildTime(vector<int> &blocks, int split)
    {
        memset(dp, -1, sizeof(dp));
        this->split = split;
        sort(blocks.begin(), blocks.end());
        Block = blocks;
        return solve(blocks.size(), 1);
    }
};

#ifdef WIN32
int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<int> arg(n);
    for (auto &x : arg)
        cin >> x;
    cin >> n;
    cout << s.minBuildTime(arg, n);
}
#endif