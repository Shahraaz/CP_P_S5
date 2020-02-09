// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
#ifdef LOCAL
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
    while (*name == ',' || *name == ' ')
        name++;
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
    while (*names == ',' || *names == ' ')
        names++;
    const char *comma = strchr(names, ',');
    std::cerr.write(names, comma - names) << " { ";
    for (const auto &v : arg1)
        cerr << v << ' ';
    cerr << " }\n";
    PC(comma, args...);
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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
    int Solvedp(vector<int> hist)
    {
        int n = hist.size();
        // Create an empty stack. The stack holds indexes
        // of hist[] array. The bars stored in stack are
        // always in increasing order of their heights.
        stack<int> s;

        int max_area = 0;  // Initialize max area
        int tp;            // To store top of stack
        int area_with_top; // To store area with top bar
                           // as the smallest bar

        // Run through all bars of given histogram
        int i = 0;
        while (i < n)
        {
            // If this bar is higher than the bar on top
            // stack, push it to stack
            if (s.empty() || hist[s.top()] <= hist[i])
                s.push(i++);

            // If this bar is lower than top of stack,
            // then calculate area of rectangle with stack
            // top as the smallest (or minimum height) bar.
            // 'i' is 'right index' for the top and element
            // before top in stack is 'left index'
            else
            {
                tp = s.top(); // store the top index
                s.pop();      // pop the top

                // Calculate the area with hist[tp] stack
                // as smallest bar
                area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

                // update max area, if needed
                if (max_area < area_with_top)
                    max_area = area_with_top;
            }
        }

        // Now pop the remaining bars from stack and calculate
        // area with every popped bar as the smallest bar
        while (s.empty() == false)
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);

            if (max_area < area_with_top)
                max_area = area_with_top;
        }

        return max_area;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;
        int maxArea = 0;
        // vector<int> dp(matrix[0].size());
        // for (size_t i = 0; i < matrix.size(); i++)
        // {
        //     for (int j = 0; j < matrix[0].size(); j++)
        //         dp[j] = matrix[i][j] == '0' ? 0 : dp[j] + 1;
        //     maxArea = max(maxArea, Solvedp(dp));
        // }
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
                    maxArea = max(maxArea, dp[i][j]);
                }
            }
            /* code */
        }

        return maxArea * maxArea;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif