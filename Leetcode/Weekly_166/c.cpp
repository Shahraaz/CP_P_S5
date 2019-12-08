#ifdef LOCAL
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
    vector<int> nums;
    bool solve(int num, int threshold)
    {
        long long sum = 0;
        for (int x : nums)
            sum += ceil((double)x / num);
        db(sum, num, threshold);
        return sum <= threshold;
    }

public:
    int smallestDivisor(vector<int> nums, int threshold)
    {
        this->nums = nums;
        int low = 1, high = *max_element(nums.begin(), nums.end()) + 1, ans = 1;
        while (low <= high)
        {
            int mid = ((ll)low + high) / 2;
            if (solve(mid, threshold))
                ans = mid, high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    cout << s.smallestDivisor({1, 2, 5, 9}, 6) << '\n';
    cout << s.smallestDivisor({2, 3, 5, 7, 11}, 11) << '\n';
}
#endif