// Optimise
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()

const int NAX = 2e5 + 5, MOD = 1000000007;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
    int level(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(level(root->left), level(root->right)) + 1;
    }
    vector<pair<int, int>> temp;
    void dfs(TreeNode *root, int level, int offset)
    {
        if (root == nullptr)
            return;
        dfs(root->left, level + 1, offset * 2);
        dfs(root->right, level + 1, offset * 2 + 1);
        temp[level].f = min(temp[level].f, offset);
        temp[level].s = max(temp[level].s, offset);
    }

public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int maxDepth = level(root);
        temp = vector<pair<int, int>>(maxDepth + 1, pair<int, int>(MOD, -MOD));
        dfs(root, 0, 0);
        int ret = 0;
        for (auto &x : temp)
            ret = max(ret, x.s - x.f);
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        ;
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif