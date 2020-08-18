#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;


constexpr int F = 2048;
struct Edge{ int v; long long weight; };	// input edges
struct PQ{ long long d; int v; };			// distance and target
bool operator>(const PQ &l, const PQ &r){
	if(l.v/F != r.v/F) return l.v > r.v;
   	return l.d > r.d;
}

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
	
	long long maxdepth = n;
	/*
	// This solution is TLE because maxdepth is always set to n.
	// Normal Dijkstra to find the shortest path.
	{
		vector<long long> dist(n,1e17);
		vector<long long> len(n,-1);
		priority_queue<PQ,vector<PQ>,greater<PQ>> pq;
		dist[s] = 0; pq.push({0, s});
		len[s] = 0;
		vector<int> parent(n, -1);
		while (!pq.empty()) {
			auto d = pq.top().d; auto u = pq.top().v; pq.pop();
			if(u == t) break;
			if (d == dist[u]){
				for(auto &e : edges[u]){
					int v = e.v;
					if (dist[v] > d + e.weight){
						parent[v] = u;
						len[v] = len[u] + 1;
						pq.push({dist[v] = d + e.weight, v});
					}
					if (dist[v] == d+e.weight){
						len[v] = max(len[v], len[u] + 1);
					}
				}
			}
		}
		maxdepth = len[t];
		cerr << "MAXDEPTH: " << maxdepth << endl;
	}
	*/

	// Each state (node, dist) is written as n*dist + node
	int N = F * (n+1);
	vector<long long> dist(N,1e17);
	vector<vector<int>> parents(N);
	priority_queue<PQ,vector<PQ>,greater<PQ>> pq;
	dist[s] = 0; pq.push({0, s});
	int dijkstras = 0;
	while (!pq.empty()) {
		auto d = pq.top().d; auto u = pq.top().v; pq.pop();
		int un = u%F;
		int ud = u/F;
		assert(u < N);
		if (d == dist[u]){
			if(ud >= maxdepth) continue;
			for(auto &e : edges[un]){
				++dijkstras;
				int v = (ud+1)*F+e.v;
			   	if (dist[v] ==  d + e.weight){
					parents[v].push_back(u);
				}
			   	if (dist[v] > d + e.weight){
					pq.push({dist[v] = d + e.weight, v});
					parents[v].assign(1, u);
				}
			}
		}
	}
	cerr << "DIJKSTRAS: " << dijkstras << endl;

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
