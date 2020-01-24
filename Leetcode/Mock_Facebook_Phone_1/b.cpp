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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    map<TreeNode *, int> depth;
    map<TreeNode *, int> dp;
    int maxiD = 0;
    int pre(TreeNode *root, int d = 0)
    {
        if (root == nullptr)
            return 0;
        pre(root->left, d + 1);
        pre(root->right, d + 1);
        maxiD = max(maxiD, d);
        return depth[root] = d;
    }

    int cnt(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (dp.find(root) != dp.end())
            return dp[root];
        cout << root->val << ' ' << dp[root] << '\n';
        if (depth[root] == maxiD)
            return dp[root] = 1;
        else
            return dp[root] = cnt(root->left) + cnt(root->right);
    }
    TreeNode *solve(TreeNode *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        int lef = cnt(root->left);
        int rig = cnt(root->right);
        cout << root->val << ' ' << lef << ' ' << rig << '\n';
        if (lef > 0 && rig > 0)
            return root;
        else if (lef > 0)
            return solve(root->left);
        else
            return solve(root->right);
    }

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        maxiD = 0;
        if (root == nullptr)
            return root;
        if (root->left == nullptr && root->right == nullptr)
            return root;
        return solve(root);
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