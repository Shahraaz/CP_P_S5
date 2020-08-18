#include <iostream>
#include <vector>
#include <algorithm>
#include <cfloat>
#include <set>
#include <random>
using namespace std;

int n, m, a, b, l;
vector<pair<pair<int, int>, double>> edges;
vector<pair<int, double>> adj[2000];
double dists[2000];
bool vis[2000];
set<int> seen;
double maxi;

void rec(int curNode, double v, double c) {
	if (vis[curNode]) return;
	vis[curNode] = true;
	seen.insert(curNode);
	if (curNode == 0) return;
	for (auto edge : adj[curNode]) if (!vis[edge.first]) {
		if (abs(dists[curNode] - (edge.second/v + c) - dists[edge.first]) < 1.e-6) rec(edge.first, v, c);
	}
}

void walk(double v, double c) {
	dists[0] = 0;
	for (int i = 1; i < n; i++) dists[i] = DBL_MAX;
	for (int i = 0; i < n; i++) for (auto edge : edges) {
		dists[edge.first.second] = min(dists[edge.first.second], dists[edge.first.first] + (edge.second/v + c));
	}
	for (int i = 0; i < n; i++) vis[i] = false;
	rec(n-1, v, c);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> l;
		a--; b--;
		edges.push_back(make_pair(make_pair(a,b), l));
		edges.push_back(make_pair(make_pair(b,a), l));
		adj[a].push_back(make_pair(b, l));
		adj[b].push_back(make_pair(a, l));
		maxi = max(maxi, (double)l);
	}
	for (double x = 1; x < 1e5; x *= 2) {
		walk(x, 0);
		walk(x, 1);
		walk(1, x);
		walk(0, x);
		walk(x, x);
		walk(x/5, x);
		walk(x, x/5);
	}
	default_random_engine re;
	uniform_real_distribution<double> unif(DBL_MIN,maxi);
	for (int i = 0; i < 10; i++) walk(unif(re), unif(re));
	set<int> drop;
	for (int i = 0; i < n; i++) if (!seen.count(i)) drop.insert(i);
	cout << drop.size() << endl;
	for (int d : drop) cout << (d+1) << " ";
	cout << endl;
}
