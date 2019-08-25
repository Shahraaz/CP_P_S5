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
    int Freq(string a)
    {
        sort(a.begin(), a.end());
        return count(a.begin(), a.end(), a[0]);
    }

public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> freq;
        for (auto s : words)
            freq.push_back(Freq(s));
        sort(freq.begin(), freq.end());
        vector<int> ret;
        for (auto s : queries)
        {
            int f = Freq(s);
            int cal = upper_bound(freq.begin(), freq.end(), f) - freq.begin();
            ret.push_back(freq.size() - cal);
        }
        return ret;
    }
};