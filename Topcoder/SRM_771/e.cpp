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
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int nax = 2e5 + 10;

class TrianglePath
{
public:
    vector<int> construct(int N, int Xmax, int Ymax, vector<int> Xprefix, vector<int> Yprefix, int seed)
    {
        auto X = Xprefix;
        auto Y = Yprefix;
        auto state = seed;
        while (X.size() < N)
        {
            state = (state * 1103515245LL + 12345) % (1 << 31);
            auto xnew = state % (Xmax + 1);
            state = (state * 1103515245LL + 12345) % (1 << 31);
            auto ynew = state % (Ymax + 1);
            if (ynew * Xmax <= (Xmax - xnew) * Ymax)
                X.push_back(xnew), Y.push_back(ynew);
        }
        while (true)
        {
            vector<int> P;
            P.pb(Random<int>{0, N - 1}(rng));
            vector<bool> Used(N);
            Used[P[0]] = true;
            ll tot = 0;
            for (int i = 1; i < N; ++i)
            {
                ll dist = 1e18;
                int b = -1;
                for (int j = 0; j < N; ++j)
                    if (!Used[j])
                    {
                        ll a = ll(X[P[i - 1] - X[j]]) * (X[P[i - 1] - X[j]]) +
                               ll(Y[P[i - 1] - Y[j]]) * (Y[P[i - 1] - Y[j]]);
                        if (a < dist)
                            dist = a, b = j;
                    }
                P.push_back(b);
                Used[b] = true;
                tot += dist;
            }
            if (tot < (ll)Xmax * Xmax + (ll)Ymax * Ymax)
                return P;
        }
        return {};
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