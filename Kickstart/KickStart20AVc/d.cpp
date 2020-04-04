// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

struct Trie
{
    Trie *child[26];
    int cnt;
    Trie()
    {
        cnt = 0;
        // memset(child, 0, sizeof child);
        for (size_t i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
    void insert(string str)
    {
        auto curr = this;
        db(str);
        for (auto &c : str)
        {
            db(c, c - 'A');
            // curr->cnt++;
            if (curr->child[c - 'A'] == nullptr)
                curr->child[c - 'A'] = new Trie();
            curr = curr->child[c - 'A'];
        }
        curr->cnt++;
    }
    static int answer;
    int dfs(int depth, int k)
    {
        int curr = cnt;
        for (size_t i = 0; i < 26; i++)
        {
            if (child[i] != nullptr)
            {
                cnt++;
                curr += child[i]->dfs(depth + 1, k);
            }
        }
        while (curr >= k)
        {
            answer += depth ;
            curr -= k;
        }
        return curr;
    }
};
int Trie::answer = 0;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n, k;
        cin >> n >> k;
        Trie::answer = 0;
        Trie nt;
        for (size_t i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            nt.insert(str);
        }
        nt.dfs(0, k);
        cout << Trie::answer << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}