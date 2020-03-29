// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
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

const int _n = 2e5 + 10;
vector<int> Fact(_n), Inv(_n);
const int kmod = 1000000007;

int mul(int a, int b, int mod = kmod)
{
    return (long long)a * b % mod;
}

int add(int a, int b, int mod = kmod)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b, int mod = kmod)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int power(int base, int index, int mod = kmod)
{
    if (index == 0)
        return 1;
    int temp = power(base, index / 2, mod);
    temp = mul(temp, temp, mod);
    if (index & 1)
        temp = mul(temp, base, mod);
    return temp;
}

int mod_inv(int x, int mod = kmod)
{
    return power(x, kmod - 2);
}

void pre()
{
    Fact[0] = 1;
    for (int i = 1; i < _n; ++i)
        Fact[i] = mul(Fact[i - 1], i);
    Inv[_n - 1] = mod_inv(Fact[_n - 1]);
    for (int i = _n - 2; i >= 0; --i)
        Inv[i] = mul(Inv[i + 1], (1 + i));
}

int ncr(int n, int r)
{
    if (n < 0 || r < 0 || n - r < 0)
        return 0;
    return mul(Fact[n], mul(Inv[r], Inv[n - r]));
}

vector<int> adj[NAX];
int sz[NAX];
int subTreeWaysDen[NAX];
int res[NAX], answer[NAX];
int num;

class Solution
{
private:
    void dfsInit(int node, int par)
    {
        sz[node] = 1;
        subTreeWaysDen[node] = 1;
        for (auto &child : adj[node])
            if (child != par)
            {
                dfsInit(child, node);
                sz[node] += sz[child];
                subTreeWaysDen[node] = mul(subTreeWaysDen[node], sz[child]);
            }
    }
    void dfsCalc0(int node, int par)
    {
        if (sz[node] == 1)
        {
            res[node] = 1;
            // db(node, par, res[node], sz[node]);
            // db("end");
            return;
        }
        res[node] = Fact[sz[node] - 1];
        for (auto &child : adj[node])
            if (child != par)
            {
                dfsCalc0(child, node);
                res[node] = mul(res[node], res[child]);
                res[node] = mul(res[node], Inv[sz[child]]);
                // db(node, child, res[node], res[child]);
            }
        // db(node, par, res[node], sz[node]);
        // db("end");
    }
    void dfsFinal(int node, int par)
    {
        // sz[node] = n;
        db(node, par, sz[node]);
        res[node] = Fact[sz[node] - 1];
        for (auto &child : adj[node])
        {
            res[node] = mul(res[node], res[child]);
            res[node] = mul(res[node], Inv[sz[child]]);
            db(node, child, res[node], res[child], sz[child]);
        }
        ll currWays = res[node];
        int szOld = sz[node];
        res[node] = mul(res[node], Inv[szOld]);
        answer[node] = currWays;
        for (auto &child : adj[node])
            if (child != par)
            {
                res[node] = currWays;

                res[node] = mul(res[node], Inv[sz[node] - 1]);
                sz[node] = n - sz[child];
                res[node] = mul(res[node], Fact[sz[node] - 1]);

                res[node] = mul(res[node], Fact[sz[child]]);
                res[node] = mul(res[node], mod_inv(res[child]));

                int oldCsz = sz[child];
                sz[child] = n;
                dfsFinal(child, node);

                sz[node] = szOld;
                sz[child] = oldCsz;
            }
    }

public:
    int n;
    Solution()
    {
        pre();
    }
    ~Solution() {}
    void solveCase()
    {
        cin >> n;
        for (size_t i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfsInit(1, 1);
        num = Fact[n - 1];
        dfsCalc0(1, 1);
        dfsFinal(1, 1);
        for (size_t i = 0; i < n; i++)
            cout << answer[i + 1] << '\n';
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
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}