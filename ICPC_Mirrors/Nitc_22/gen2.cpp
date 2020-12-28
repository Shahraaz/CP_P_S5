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
    int n = rand() % 20 + 1;
    // ;
    // cin >> n;
    ifstream MyReadFile("/home/shahraaz/Documents/CP/CP_P_S5/ICPC_Mirrors/Nitc_22/in");
    MyReadFile >> n;
    cout << n << endl;
    vector<int> vecc(n);
    for (size_t i = 0; i < n; i++)
    {
        MyReadFile >> vecc[i];
    }
    // random_shuffle(all(vecc));
    db(vecc.size(), vecc);
    int cnt = 0;
    while (true)
    {
        string str;
        cin >> str;
        if (str == "ASK")
        {
            int k;
            cin >> k;
            cnt++;
            assert(cnt <= 32);
            for (size_t i = 0; i < k; i++)
            {
                int x;
                cin >> x;
                --x;
                cout << vecc[x] << ' ';
            }
            cout << endl;
        }
        else
        {
            for (size_t i = 0; i < n; i++)
            {
                int x;
                cin >> x;
                if (x != vecc[i])
                {
                    cout << "Failed \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout << vecc.size() << ' ';
                    for (auto &x : vecc)
                    {
                        cout << x << ' ';
                    }
                    cout << endl;
                    assert(x == vecc[i]);
                }
                // db(vecc.size(), vecc);
                // if(x != vecc[i])
            }
            cout << "success\n";
            cout << cnt << endl;
            return;
        }
    }
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