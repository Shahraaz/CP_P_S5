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
    string str;
    cin >> str;
    vector<int> score(2);
    vector<int> rounds(2);
    bool turn = false;
    auto check_if_over = [&]() -> bool {
        return rounds[0] >= 2 || rounds[1] >= 2;
    };
    auto change_score = [&](char ch) {
        if (check_if_over())
            return;
        if (ch == 'S')
        {
            score[turn]++;
        }
        else
        {
            turn = !turn;
            score[turn]++;
        }
        if (abs(score[0] - score[1]) >= 2)
        {
            if (max(score[0], score[1]) >= 5)
            {
                rounds[turn]++;
                score[0] = score[1] = 0;
            }
        }
        else if (max(score[0], score[1]) >= 10)
        {
            rounds[turn]++;
            score[0] = score[1] = 0;
        }
    };
    auto announce = [&]() {
        if (check_if_over())
        {
            cout << rounds[0];
            if (rounds[0] >= 2)
                cout << " (winner)";
            cout << " - ";
            cout << rounds[1];
            if (rounds[1] >= 2)
                cout << " (winner)";
            cout << '\n';
        }
        else
        {
            cout << rounds[0] << ' ' << "(" << score[0];
            if (turn == 0)
                cout << "*";
            cout << ") - ";
            cout << rounds[1] << ' ' << "(" << score[1];
            if (turn == 1)
                cout << "*";
            cout << ")\n";
        }
    };
    for (auto &x : str)
        if (x == 'Q')
            announce();
        else
            change_score(x);
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