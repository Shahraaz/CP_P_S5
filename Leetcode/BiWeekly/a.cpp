#include<bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
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
    int calculateTime(string keyboard, string word)
    {
        map<char, int> Ind;
        for (int i = 0; i < 26; ++i)
            Ind[keyboard[i]] = i;
        int res = 0, prev = 0;
        for (auto c : word)
        {
            res += abs(Ind[c] - prev);
            prev = Ind[c];
        }
        return res;
    }
};