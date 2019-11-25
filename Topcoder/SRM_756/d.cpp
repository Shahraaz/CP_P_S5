//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
// #define Debug
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

class CrazyCrazy
{
public:
    string possible(string song)
    {
        map<char, deque<int>> pos;
        int n = song.size();
        vector<bool> taken(n);
        for (int i = 0; i < n; ++i)
            pos[song[i]].pb(i);
        int posb;
        posb = -1;
        for (int i = 0; i < n; ++i)
        {
            db(i);
            if (taken[i])
                continue;
            if (pos[song[i]].size() == 0)
                return "impossible";
            pos[song[i]].pop_front();
            if (pos[song[i]].size())
            {
                auto Pos = -1;
                bool k = false;
                for (auto j = pos[song[i]].begin(); j != pos[song[i]].end(); ++j)
                {
                    Pos = *j;
                    if (Pos >= posb)
                    {
                        k = true;
                        pos[song[i]].erase(j);
                        break;
                    }
                }
                if(k)
                {
                    posb = Pos;
                    taken[posb] = true;
                }
                else
                return "impossible";
            }
            else
                return "impossible";
            db(posa,posb);
        }
        return "possible";
    }
};
