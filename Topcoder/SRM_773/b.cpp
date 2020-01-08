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
#define all(v) (v).begin(), (v).end()
const long long mod = 1000000007;

const int nax = 2e5 + 10;

class ChristmasPudding
{
public:
    long long eat(int N, long long Vall, long long Vsweet, vector<int> Vprefix, vector<int> Tprefix, vector<int> Sprefix, int seed)
    {
        auto V = Vprefix;
        auto T = Tprefix;
        auto S = Sprefix;
        ll state = seed;
        while (V.size() < N)
        {
            state = (state * 1103515245 + 12345) % (1 << 31);
            V.pb(1 + (state % (1000000)));
            state = (state * 1103515245 + 12345) % (1 << 31);
            T.pb(1 + (state % (1000000)));
            state = (state * 1103515245 + 12345) % (1 << 31);
            S.pb((state / 1024) % 2);
        }
        ll res = 0;
        vector<pair<int, int>> sweet, savory;
        for (size_t i = 0; i < N; i++)
            if (S[i])
                sweet.pb({T[i], V[i]});
            else
                savory.pb({T[i], V[i]});
        sort(all(sweet));
        sort(all(savory));
        reverse(all(sweet));
        reverse(all(savory));
        int ptr1, ptr2;
        ptr1 = ptr2 = 0;
        while (Vsweet > 0 || Vall > 0)
        {
            if (Vsweet > 0)
            {
                if (ptr1 == sweet.size())
                    Vsweet = 0;
                else
                {
                    ll curr = min(Vsweet, (ll)sweet[ptr1].s);
                    Vsweet -= curr;
                    Vall -= curr;
                    sweet[ptr1].s -= curr;
                    res += sweet[ptr1].f * curr;
                    if (sweet[ptr1].s == 0)
                        ptr1++;
                }
            }
            else
            {
                if (ptr1 == sweet.size())
                {
                    if (ptr2 == savory.size())
                        Vall = 0;
                    else
                    {
                        ll curr = min(Vall, (ll)savory[ptr2].s);
                        Vall -= curr;
                        savory[ptr2].s -= curr;
                        res += savory[ptr2].f * (curr);
                        if (savory[ptr2].s == 0)
                            ptr2++;
                    }
                }
                else if (ptr2 == savory.size())
                {
                    ll curr = min(Vall, (ll)sweet[ptr1].s);
                    Vall -= curr;
                    sweet[ptr1].s -= curr;
                    res += sweet[ptr1].f * (curr);
                    if (sweet[ptr1].s == 0)
                        ptr1++;
                }
                else
                {
                    if (sweet[ptr1].f > savory[ptr2].f)
                    {
                        ll curr = min(Vall, (ll)sweet[ptr1].s);
                        Vall -= curr;
                        sweet[ptr1].s -= curr;
                        res += sweet[ptr1].f * (curr);
                        if (sweet[ptr1].s == 0)
                            ptr1++;
                    }
                    else
                    {
                        ll curr = min(Vall, (ll)savory[ptr2].s);
                        Vall -= curr;
                        savory[ptr2].s -= curr;
                        res += savory[ptr2].f * (curr);
                        if (savory[ptr2].s == 0)
                            ptr2++;
                    }
                }
            }
        }
        return res;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int
main()
{
    return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!