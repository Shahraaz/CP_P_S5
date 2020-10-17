#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
mt19937 rnd(228);
#else
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 1000 + 7;

int dp[N][N];

int main() {
#ifdef iq
    freopen("a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    vector <pair <int, int> > e;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '.') {
                if (s[i][j] != 'A')
                    e.push_back({i, j});
                else
                    x = i, y = j;
            }
        }
    }
    auto f = [&] (int l, int r) {
        int vl = 0, vr = m - 1;
        for (auto c : e) {
            if (l <= c.first && c.first <= r) {
                if (c.second >= y) {
                    vr = min(vr, c.second - 1);
                } else {
                    vl = max(vl, c.second + 1);
                }
            }
        }
        if (vr < y || vl > y) return -228;
        return vr - vl + 1;
    };
    int ans = 0;
    int i = x, j = x;
    for (int l = 0; l <= x; l++) {
        for (int r = x; r < n; r++) {
            auto ok = f(l, r);
            if (ok < 0) {
                continue;
            }
            if (ok * (r - l + 1) > ans) {
                ans = ok * (r - l + 1);
                i = l, j = r;
            }
        }
    }
    auto cool = [&] (int l, int r) {
        int vl = 0, vr = m - 1;
        for (auto c : e) {
            if (l <= c.first && c.first <= r) {
                if (c.second >= y) {
                    vr = min(vr, c.second - 1);
                } else {
                    vl = max(vl, c.second + 1);
                }
            }
        }
//        cout << l << " " << r << " " << vl << " " << vr << "\n";
        for (int i = l; i <= r; i++) {
            for (int j = vl; j <= vr; j++) {
                if (s[i][j] == '.') {
                    s[i][j] = 'a';
                }
            }
        }
    };
    cool(i, j);
    for (char c = 'B'; c <= 'Z'; c++) {
        int tx = -1, ty = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] == c) {
                    tx =i , ty = j;
                }
            }
        }
        if (tx == -1) continue;
        int al = 0, ar = n - 1;
        int vl = 0, vr = m - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s[i][j] != '.' && s[i][j] != c) {
                    if (i == tx) {
                        if (j >= ty) {
                            vr = min(vr, j - 1);
                        } else {
                            vl = max(vl, j + 1);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)     {
                if (s[i][j] != '.' && s[i][j] != c) {
                    if (vl <= j && j <= vr) {
                        if (i >= tx) {
                            ar = min(ar, i - 1);
                        } else {
                            al = max(al, i + 1);
                        }
                    }
                }
            }
        }
        for (int i = al; i <= ar; i++) {
            for (int j = vl; j <= vr; j++) {
                if (s[i][j] == '.') {
                    s[i][j] = tolower(c);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << '\n';
    }
}
