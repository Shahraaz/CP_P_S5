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
    vector<int> Sum;
    void getDetails(TreeNode *root, int level)
    {
        if (root == nullptr)
            return;
        Sum[level] += root->val;
        getDetails(root->left, level + 1);
        getDetails(root->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode *root)
    {
        Sum.resize(1e4+4);
        getDetails(root, 1);
        int maxCnt, index;
        maxCnt = -1;
        for (int i = 0; i < Sum.size(); ++i)
        {
            if(Sum[i] > maxCnt)
            {
                maxCnt = Sum[i];
                index = i;
            }
        }
        return index;
    }
};
#ifdef LOCAL
int main()
{
    Solution s;
}
#endif