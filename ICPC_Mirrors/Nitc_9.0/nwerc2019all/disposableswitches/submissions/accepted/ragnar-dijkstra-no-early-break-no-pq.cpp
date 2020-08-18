#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;


constexpr int F = 2048;
struct Edge{ int v; long long weight; };	// input edges

int main(){

	int n, m; cin >> n >> m;
   	int s=0; int t=n-1;

	vector<vector<Edge>> edges(n);
	for(int i = 0; i < m; ++i){
		int u, v, w; cin >> u >> v >> w;
		--u, --v;
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}
	
	// Each state (node, dist) is written as n*dist + node
	int N = F * (n+1);
	vector<long long> dist(N,1e17);
	vector<vector<int>> parents(N);
	dist[s] = 0;
	for(int ud = 0; ud < n; ++ud){
		for(int un = 0; un < n; ++un){
			int u = ud*F+un;
			auto d = dist[u];
			if(d == 1e17) continue;
			for(auto &e : edges[un]){
				int v = (ud+1)*F+e.v;
				if (dist[v] ==  d + e.weight){
					parents[v].push_back(u);
				}
				if (dist[v] > d + e.weight){
					dist[v] = d + e.weight;
					parents[v].assign(1, u);
				}
			}
		}
	}

	// length and cost stack/convex hull
	vector<pair<__int128, __int128>> lc;
	for(int l = 0; l <= n; ++l){
		int t2 = l*F + t;
		auto d = dist[t2];
		if(lc.empty()){
			lc.push_back({l, d});
			continue;
		}

		if(d > lc.back().second) continue;
		if(lc.size() == 1){
			lc.push_back({l, d});
			continue;
		}
		while(lc.size() >= 2){
			auto pl = lc[lc.size()-2].first - l;
			auto pc = lc[lc.size()-2].second - d;
			auto ql = lc[lc.size()-1].first - l;
			auto qc = lc[lc.size()-1].second - d;
			if(pl*qc - pc*ql < 0) lc.pop_back();
			else break;
		}
		lc.push_back({l, d});
	}

	cerr << "FRONT DONE\n";

	vector<int> todo;
	for(auto x : lc) todo.push_back({x.first * F + t});

	// Walk back up the parents from all added targets.
	vector<bool> used(N, false);
	vector<bool> usednode(n, false);
	int visits = 0;
	while(!todo.empty()){
		auto u = todo.back();
		todo.pop_back();
		++visits;
		if(u < 0 or used[u]) continue;
		used[u] = true;
		usednode[u%F] = true;
		for(auto v : parents[u]) todo.push_back(v);
	}
	cerr << "VISITS: " << visits << endl;

	
	vector<int> ans;
	for(int i = 0; i < usednode.size(); ++i)
		if(not usednode[i])
			ans.push_back(i);

	cout << ans.size() << endl;
	for(auto x : ans) cout << x+1 << endl;
}
