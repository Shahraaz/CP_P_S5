#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<char> st;
    for (auto &x : str)
    {
        if (x == 'x')
        {
            if (st.size() > 1 && st.back() == 'o' && st[st.size() - 2] == 'f')
            {
                st.pop_back();
                st.pop_back();
            }
            else
                st.push_back(x);
        }
        else
            st.push_back(x);
    }
    cout << st.size() << '\n';
}

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}