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

class Solution
{
    string prepend(string a, int n)
    {
        string ret = "";
        while (n--)
        {
            ret += "0";
        }
        ret += a;
        return ret;
    }
    string apppend(string a, int n)
    {
        while (n--)
        {
            a += "0";
        }
        return a;
    }
    string add(string a, string b)
    {
        if (a.size() < b.size())
            swap(a, b);
        int carry = 0;
        b = prepend(b, a.size() - b.size());
        for (int i = a.size() - 1; i >= 0; i--)
        {
            int f = a[i] - '0';
            int s = b[i] - '0';
            f += s;
            if (carry)
                f++, carry = false;
            a[i] = (f % 10) + '0';
            carry = f / 10;
        }
        if (carry)
            a = "1" + a;
        return a;
    }
    string multiply(string num1, int num2)
    {
        if (num2 == 0)
            return "0";
        string ret = "";
        int carry = 0;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int temp = num1[i] - '0';
            temp *= num2;
            temp += carry;
            ret += (temp % 10) + '0';
            carry = temp / 10;
        }
        reverse(all(ret));
        if (carry > 0)
            ret = to_string(carry) + ret;
        return ret;
    }
    string clear_zeros(string ret)
    {
        if (ret == "0")
            return ret;
        reverse(all(ret));
        while (ret.back() == '0')
        {
            ret.pop_back();
        }
        reverse(all(ret));
        if (ret == "")
            return "0";
        return ret;
    }

public:
    string multiply(string num1, string num2)
    {
        string ret = "";
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            ret = add(ret, apppend(multiply(num2, num1[i] - '0'), num1.size() - 1 - i));
        }
        if (ret == "")
            ret = "0";
        return clear_zeros(ret);
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