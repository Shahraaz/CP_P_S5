#ifndef LOCAL
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
    vector<int> dpOdd, dpEven;
    int n;

public:
    int oddEvenJumps(vector<int> &A)
    {
        n = A.size();
        dpOdd.resize(n, 1);
        dpEven.resize(n);
        map<int, set<int>> S;
        for (int i = 0; i < n; ++i)
            S[A[i]].insert(i);
        for (int i = 0; i < n; ++i)
        {
            S[A[i]].erase(i);
            if (S[A[i]].size() == 0)
                S.erase(A[i]);
            if (dpOdd[i])
            {
                auto it = S.lower_bound(A[i]);
                if (it != S.end())
                    dpEven[*(it->s).begin()] += dpOdd[i];
            }
            if (dpEven[i])
            {
                auto it = S.lower_bound(A[i]);
                if (it != S.end())
                {
                    if (it->f == A[i])
                    {
                        dpOdd[*(it->s).begin()] += dpEven[i];
                    }
                    else
                    {
                        if (it != S.begin())
                        {
                            --it;
                            dpOdd[*(it->s).begin()] += dpEven[i];
                        }
                    }
                }
                else
                {
                    if (it != S.begin())
                    {
                        --it;
                        dpOdd[*(it->s).begin()] += dpEven[i];
                    }
                }
            }
        }
        return dpOdd[n - 1] + dpEven[n - 1];
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
}
#endif