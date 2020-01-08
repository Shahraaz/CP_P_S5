//Optimise
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

class ChristmasTravel
{
public:
    vector<string> plan(int N, int A)
    {
        int E = N * (N - 1) / 2;
        if (A > E)
            return {};
        vector<vector<pair<int, int>>> where;
        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < i; j++)
            {
                int b = i ^ j;
                for (size_t k = 0; k < INT_MAX; k++)
                    if ((b >> k) & 1)
                    {
                        if (where.size() <= k)
                            where.resize(k + 1);
                        where[k].pb({i, j});
                        break;
                    }
            }
        if (A < where.size())
            return {};
        vector<string> ans(N, string(N, '-'));
        auto make = [&](pair<int, int> b, int f) {
            ans[b.f][b.s] = f + 'A';
            ans[b.s][b.f] = f + 'A';
        };
        for (size_t i = 0; i < where.size(); i++)
            make(where[i][0], i);
        int cur = where.size();
        for (size_t i = 0; i < where.size(); i++)
        {
            int v = 1;
            while (cur < A && v < where[i].size())
            {
                make(where[i][v], cur);
                cur++;
                v++;
            }
            while (v < where.size())
            {
                make(where[i][v], i);
                ++v;
            }
        }
        return ans;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
    return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!