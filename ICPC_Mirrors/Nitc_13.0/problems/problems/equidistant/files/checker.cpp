#include <bits/stdc++.h>
#include "testlib.h"

int n, m;

const int MAX = 20;
std::vector<int> up[MAX];
std::vector<int> h;
std::vector<std::vector<int> > g;
std::vector<int> teams;

void go(int v, int p) {
    h[v] = h[p] + 1;
    up[0][v] = p;
    for (int i = 1; i < MAX; i++) {
        up[i][v] = up[i - 1][up[i - 1][v]];
    }
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        go(to, v);
    }
}

int go_up(int x, int dH) {
    for (int i = 0; i < MAX; i++) {
        if (((1 << i) & dH) != 0) {
            x = up[i][x];
        }
    }
    return x;
}

int lca(int x, int y) {
    if (h[x] > h[y]) {
        x = go_up(x, h[x] - h[y]);
    } else {
        y = go_up(y, h[y] - h[x]);
    }
    for (int i = MAX - 1; i >= 0; i--) {
        if (up[i][x] != up[i][y]) {
            x = up[i][x];
            y = up[i][y];
        }
    }
    return x == y ? x : up[0][x];
}

int dist(int x, int y) {
    return h[x] + h[y] - 2 * h[lca(x, y)];
}

inline bool readAndCheckAnswer(InStream& in) {
    std::string res = in.readToken();
    if (res != "YES" && res != "NO") {
        in.quitf(_wa, "Expected YES or NO, found '%s'", res.c_str());
    }
    if (res == "NO") {
        return false;
    }
    inf.readEoln();
    int root = in.readInt(1, n) - 1;
    int dist_v = -1, first_dist = -1;
    for (int t : teams) {
        int dist_t = dist(root, t);
        if (dist_v == -1) {
            first_dist = dist_t;
            dist_v = t;
        } else if (dist_t != first_dist) {
            in.quitf(_wa, "dist(%d, %d) = %d, dist(%d, %d) = %d", root + 1, dist_v + 1, first_dist, root + 1, t + 1, dist_t);
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt();
    m = inf.readInt();
    g.resize(n);
    for (int i = 0; i + 1 < n; i++) {
        int fr = inf.readInt() - 1;
        int to = inf.readInt() - 1;
        g[fr].push_back(to);
        g[to].push_back(fr);
    }
    for (int i = 0; i < m; i++) {
        teams.push_back(inf.readInt() - 1);
    }
    for (int i = 0; i < MAX; i++) {
        up[i].resize(n);
    }
    h.resize(n);
    go(0, 0);

    bool ja = readAndCheckAnswer(ans);
    bool pa = readAndCheckAnswer(ouf);

    if(ja && !pa)
        quitf(_wa, "Jury has the answer but participant has not");
    if(!ja && pa)
        quitf(_fail, "Participant has the answer but jury has not");

    quitf(_ok, "n = %d, m = %d", n, m);
}