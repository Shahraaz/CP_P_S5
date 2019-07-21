// #define Debug
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
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        ll ans = 0;
        map<pair<int,int>,int> Cnt;
        for(auto c:dominoes)
        {
            ans += Cnt[c];
            ans += Cnt[{c.s,c.f}];
            Cnt[c]++;
        }
        return ans;
    }
};