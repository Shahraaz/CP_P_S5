#include "validate.h"
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n;
    judge_in >> n;

    vector<set<int> > desc(n);

    for (int i = 0; i < n; i++) {
        int m;
        judge_in >> m;
        for (int j = 0; j < m; j++) {
            int d;
            judge_in >> d;
            desc[i].insert(d);
        }
    }

    string init;
    judge_ans >> init;
    bool conn_judge = init != "impossible";

    if (!(author_out >> init)) {
        wrong_answer("Empty output\n");
    }
    transform(init.begin(), init.end(), init.begin(), ::tolower);
    if (init == "impossible") {
        if (conn_judge) {
            wrong_answer("They claim disconnected, but graph is connected\n");
        }
    } else {
        if (!conn_judge) {
            wrong_answer("They claim connected, but graph is disconnected\n");
        }

        vector<vector<int> > adj(n);

        stringstream ss(init);
        for (int i = 0; i < n-1; i++) {
            int a, b, c;
            if (!((i == 0 ? ss : author_out) >> a)) {
                wrong_answer("Expected a number, got something else\n");
            }
            if (!(author_out >> b >> c)) {
                wrong_answer("Expected three numbers, got something else\n");
            }

            if (a < 1 || a > n) {
                wrong_answer("Number %d not in range [1,%d]\n", a, n);
            }
            if (b < 1 || b > n) {
                wrong_answer("Number %d not in range [1,%d]\n", b, n);
            }

            a--, b--;
            if (desc[a].find(c) == desc[a].end()) {
                wrong_answer("Number %d does not describe individual %d\n", c, a+1);
            }
            if (desc[b].find(c) == desc[b].end()) {
                wrong_answer("Number %d does not describe individual %d\n", c, b+1);
            }

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> vis(n);
        stack<int> S;
        S.push(0);
        vis[0] = true;
        while (!S.empty()) {
            int cur = S.top();
            S.pop();
            for (vector<int>::const_iterator it = adj[cur].begin(); it != adj[cur].end(); ++it) {
                if (!vis[*it]) {
                    vis[*it] = true;
                    S.push(*it);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                wrong_answer("Proof invalid. Individuals %d and %d are not connected.\n", 1, i+1);
            }
        }
    }

    string trash;
    if (author_out >> trash) {
        wrong_answer("Trailing output\n");
    }

    accept();
}
