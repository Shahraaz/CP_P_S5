#include <bits/stdc++.h>
using namespace std;

// Addition by Ragnar: Once adding a node at layer d fails, do not consider any
// more nodes at layers >= d.

int main(void) {
    int n, k;
    scanf("%d%d", &n, &k);

    vector<int> f(n+1);
    vector<array<int, 2>> children(n+1);
    int root;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        if (f[i] == -1) root = i;
        else children[f[i]][i > f[i]] = i;
    }

    vector<int> height(n+1, 0), depth(n+1, 1);
    function<void(int)> dfs = [&](int u) {
        height[u] = 1;
        for (int &c: children[u])
            if (c) {
				depth[c] = depth[u] + 1;
                dfs(c);
                height[u] = max(height[u], height[c]+1);
            }
    };
    dfs(root);

    vector<int> keep(n+1), curh(n+1);
    priority_queue<int, vector<int>, greater<int>> avail;
    avail.push(root);

    function<void(int, int, vector<int>&)> incheight = [&](int u, int h, vector<int>& res) {
        if (h <= curh[u]) return;
        if (!keep[u]) res.push_back(u);
        auto [l, r] = children[u];
        if (h-1 > height[l]) swap(l, r);
        incheight(l, h-1, res);
        incheight(r, h-2, res);
    };

	int maxd = 1e9;

    while (k) {
        int u = avail.top(); avail.pop();
        if (keep[u]) continue;
		if (depth[u] > maxd) continue;
        vector<int> take(1, u);
		int u2 = u;
        while (u2 != root) {
            int v = f[u2];
            int o = children[v][0] + children[v][1] - u2;
            if (curh[o] > curh[u2]) break;
            if (curh[o] < curh[u2]) incheight(o, curh[u2], take);
            u2 = v;
        }
        if (take.size() > k){
			maxd = depth[u] - 1;
		   	continue;
		}
        k -= take.size();
        for (int u: take) {
            auto [l, r] = children[u];
            if (l) avail.push(l);
            if (r) avail.push(r);
            curh[u] = keep[u] = 1;
            while (u != root) {
                if (curh[f[u]] >= curh[u]+1) break;
                u = f[u];
                ++curh[u];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        putchar('0'+keep[i]);
    putchar('\n');
}
