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
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int ans = -mod, best1, best, best2, best3, best4;
        best1 = best2 = best3 = best4 = -mod;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, best1 + arr1[i] + arr2[i] + i);
            ans = max(ans, best2 - arr1[i] + arr2[i] + i);
            ans = max(ans, best3 + arr1[i] - arr2[i] + i);
            ans = max(ans, best4 - arr1[i] - arr2[i] + i);
            best1 = max(best1, -arr1[i] - arr2[i] - i);
            best2 = max(best2, arr1[i] - arr2[i] - i);
            best3 = max(best3, -arr1[i] + arr2[i] - i);
            best4 = max(best4, arr1[i] + arr2[i] - i);
        }
        return ans;
    }
};