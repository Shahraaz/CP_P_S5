#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    int m = inf.readInt();
    inf.readEoln();
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = inf.readString();
    }
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = ouf.readString();
        if (b[i].size() != m) {
            quitf(_wa, "Length of line is %d, expected to be %d", m, (int)b[i].size());
        }
    }
    vector<string> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = ans.readString();
    }

    vector<int> l(26, m), r(26, -1), u(26, n), d(26, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            if (b[i][j] >= 'A' && b[i][j] <= 'Z') {
                x = b[i][j] - 'A';
                if (b[i][j] != a[i][j]) {
                    quitf(_wa, "Castle (%d, %d) where it was not", i, j);
                }
            } else if (b[i][j] >= 'a' && b[i][j] <= 'z') {
                x = b[i][j] - 'a';
                if (a[i][j] != '.') {
                    quitf(_wa, "No castle (%d, %d) where it was", i, j);
                }
            } else {
                quitf(_wa, "Unexpected character: %c", b[i][j]);
            }
            u[x] = min(u[x], i);
            d[x] = max(d[x], i);
            l[x] = min(l[x], j);
            r[x] = max(r[x], j);
        }
    }

    for (int x = 0; x < 26; x++) {
        if (r[x] == -1) continue;
        for (int i = u[x]; i <= d[x]; i++) {
            for (int j = l[x]; j <= r[x]; j++) {
                if (b[i][j] != ('a' + x) && b[i][j] != ('A' + x)) {
                    quitf(_wa, "Shape is not rectangular: %c", (char)('A' + x));
                }
            }
        }
    }

    int pa = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == 'a') pa++;
        }
    }
    int ja = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'a') ja++;
        }
    }
    if (pa > ja) {
        quitf(_fail, "Participant's answer is better: %d instead of %d", pa, ja);
    }
    if (pa < ja) {
        quitf(_wa, "Participant's answer is worse: %d instead of %d", pa, ja);
    }

    quitf(_ok, "");
}
