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
    int minFlips(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1;
        const int lim1 = (n * m);
        const int lim2 = 1 << (lim1);
        for (int i = 0; i < lim2; ++i)
        {
            auto y = mat;
            for (int j = 0; j < lim1; ++j)
                if (i & (1 << j))
                {
                    int a = j / m, b = j % m;
                    y[a][b] ^= 1;
                    if (a != 0)
                        y[a - 1][b] ^= 1;
                    if (b != 0)
                        y[a][b - 1] ^= 1;
                    if (a != (n - 1))
                        y[a + 1][b] ^= 1;
                    if (b != (m - 1))
                        y[a][b + 1] ^= 1;
                }
            bool ok = true;
            for (auto j : y)
                for (auto k : j)
                    ok = ok && (!k);
            if (ok)
                if ((ans == -1) || (__builtin_popcount(i) < ans))
                    ans = __builtin_popcount(i);
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
}
#endif