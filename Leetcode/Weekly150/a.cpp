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
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> Hash(26);
        for (auto c : chars)
            Hash[c - 'a']++;
        int ret = 0;
        for (auto s : words)
        {
            vector<int> H(26);
            for (auto c : s)
                H[c - 'a']++;
            bool yes = true;
            for (int i = 0; i < 26; ++i)
            {
                if (Hash[i] < H[i])
                    yes = false;
            }
            if (yes)
                ret += s.length();
        }
        return ret;
    }
};