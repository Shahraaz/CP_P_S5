#include <bits/stdc++.h>
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
using ll = long long;
class Solution
{
public:
    long long connectSticks(vector<int> sticks)
    {
        multiset<int> S;
        for (int i = 0; i < sticks.size(); ++i)
            S.insert(sticks[i]);
        ll ans = 0;
        while (S.size() > 1)
        {
            auto it = S.begin();
            ll temp1 = *it;
            auto it2 = it;
            ++it2;
            ll temp2 = *it2;
            S.erase(it);
            S.erase(it2);
            ans += (temp1 + temp2);
            S.insert(temp1 + temp2);
        }
        return ans;
    }
};