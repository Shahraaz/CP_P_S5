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

const int NAX = 2e5 + 5, MOD = 1000000000;

const int _n = 2e5 + 10;
vector<int> Fact(_n), Inv(_n);
const int kmod = 1000000000;

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

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        string str;
        cin >> str;
        pair<int, int> curr;
        curr = {0, 0};
        stack<pair<pair<int, int>, int>> st;
        for (int i = 0; i < str.size(); i++)
        {
            auto c = str[i];
            if ('0' <= c && c <= '9')
            {
                st.push({curr, c - '0'});
                curr = {0, 0};
                ++i;
            }
            else if (c == ')')
            {
                auto prev = st.top();
                st.pop();
                prev.f.f = add(prev.f.f, mul(curr.f, prev.s));
                prev.f.s = add(prev.f.s, mul(curr.s, prev.s));
                curr = prev.f;
            }
            else
            {
                switch (c)
                {
                case 'N':
                    curr.s = sub(curr.s, 1);
                    break;
                case 'S':
                    curr.s = add(curr.s, 1);
                    break;
                case 'E':
                    curr.f = add(curr.f, 1);
                    break;
                case 'W':
                    curr.f = sub(curr.f, 1);
                    break;
                default:
                    break;
                }
            }
        }
        cout << curr.f + 1 << ' ' << curr.s + 1 << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef LOCAL
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
