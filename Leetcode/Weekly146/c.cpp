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
    map<pair<int, int>, int> Dp;
    int mctFromleafValue(vector<int> &arr, int left, int right)
    {
        int size = right - left + 1;
        if (size <= 1)
            return 0;
        if (size == 2)
        {
            cout << left << ' ' << right << ' ' << arr[left] * arr[right] << '\n';
            return arr[left] * arr[right];
        }
        auto it = Dp.find({left, right});
        if (it != Dp.end())
            return it->s;
        multiset<int> M;
        for (int i = left; i <= right; ++i)
            M.insert(arr[i]);
        int ans = 1e9, lmin = arr[left];
        auto it2 = M.find(arr[left]);
        M.erase(it2);
        for (int i = left + 1; i <= right; ++i)
        {
            int rmin = *M.rbegin();
            ans = min(ans, lmin * rmin + mctFromleafValue(arr, left, i - 1) + mctFromleafValue(arr, i, right));
            lmin = max(lmin, arr[i]);
            auto it = M.find(arr[i]);
            M.erase(it);
        }
        cout << left << ' ' << right << ' ' << ans << '\n';
        return Dp[{left, right}] = ans;
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        return mctFromleafValue(arr, 0, arr.size() - 1);
    }
};