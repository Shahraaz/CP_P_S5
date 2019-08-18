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
    vector<long long> Sum;
    void Recurse(TreeNode *root, int level)
    {
        //cout << level << '\n';
        if (root == NULL)
            return;
        //cout << root->val << ' ' << level << '\n';
        Sum[level] += root->val;
        Recurse(root->left, level + 1);
        Recurse(root->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode *root)
    {
        Sum = vector<long long>(1e5);
        Recurse(root, 1);
        return max_element(Sum.begin(), Sum.end()) - Sum.begin();
    }
};