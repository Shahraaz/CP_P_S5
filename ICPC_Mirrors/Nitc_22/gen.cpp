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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solveCase()
{
    ifstream MyReadFile("/home/shahraaz/Documents/CP/CP_P_S5/ICPC_Mirrors/Nitc_22/in2");
    int n = uniform_int_distribution<int>(1, 100)(rng);
    MyReadFile >> n;
    cout << n << endl;
    vector<int> vecc(n);
    for (size_t i = 0; i < n; i++)
        vecc[i] = i + 1;
    shuffle(all(vecc), rng);
    for (size_t i = 0; i < n; i++)
        cout << vecc[i] << ' ';
    cout << '\n';
}

int32_t main()
{
    srand(time(NULL));
#ifndef LOCAL
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
#endif
    int t = 1;
    // cout << t << endl;
    // int x;
    // cin >> x;
    // assert(x == t);
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}