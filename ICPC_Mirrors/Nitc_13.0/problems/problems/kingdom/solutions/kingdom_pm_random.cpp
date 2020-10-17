#include <bits/stdc++.h>

using namespace std;

long seed = 263172936192361732LL;

int rand() {
    seed = 1726391263971263 * seed + 1729316729316293162;
    seed ^= seed >> 24;
    return (int) (seed & 0x7fffffff);
}

int main(int argc, char *argv[]) {

    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> x(26, -1), y(26, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '.') {
                int c = a[i][j] - 'A';
                x[c] = i;
                y[c] = j;
            }
        }
    }
    vector<string> aa = a;
    vector<string> best;
    int maxs = -1;
    for (int qq = 0; qq < 50; qq++) {
        a = aa;
        for (int k = 0; k < 26; k++) {
            if (x[k] == -1) continue;
            int x1 = x[k];
            int x2 = x[k];
            int y1 = y[k];
            int y2 = y[k];
            bool okx1 = true;
            bool okx2 = true;
            bool oky1 = true;
            bool oky2 = true;
            while (okx1 || okx2 || oky1 || oky2) {
                int d = rand() % 4;
                if (okx1 && d == 0) {
                    if (x1 == 0) {
                        okx1 = false;
                    } else {
                        for (int i = y1; i <= y2; i++) {
                            if (a[x1 - 1][i] != '.') {
                                okx1 = false;
                            }
                        }
                    }
                    if (okx1) {
                        x1--;
                    }
                }
                if (okx2 && d == 1) {
                    if (x2 == n - 1) {
                        okx2 = false;
                    } else {
                        for (int i = y1; i <= y2; i++) {
                            if (a[x2 + 1][i] != '.') {
                                okx2 = false;
                            }
                        }
                    }
                    if (okx2) {
                        x2++;
                    }
                }
                if (oky1 && d == 2) {
                    if (y1 == 0) {
                        oky1 = false;
                    } else {
                        for (int i = x1; i <= x2; i++) {
                            if (a[i][y1 - 1] != '.') {
                                oky1 = false;
                            }
                        }
                    }
                    if (oky1) {
                        y1--;
                    }
                }
                if (oky2 && d == 3) {
                    if (y2 == m - 1) {
                        oky2 = false;
                    } else {
                        for (int i = x1; i <= x2; i++) {
                            if (a[i][y2 + 1] != '.') {
                                oky2 = false;
                            }
                        }
                    }
                    if (oky2) {
                        y2++;
                    }
                }
            }
            for (int i = x1; i <= x2; i++) {
                for (int j = y1; j <= y2; j++) {
                    if (a[i][j] == '.') {
                        a[i][j] = (char) ('a' + k);
                    }
                }
            }
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'a') s++;
            }
        }
        cerr << s << "\n";
        if (s > maxs) {
            maxs = s;
            best = a;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << best[i] << "\n";
    }
}