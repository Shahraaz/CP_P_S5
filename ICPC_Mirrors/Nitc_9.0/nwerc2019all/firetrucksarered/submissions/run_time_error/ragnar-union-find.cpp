#include <iostream>
#include <vector>
using namespace std;


struct UnionFind {
	vector<int> par, rank, size; int c;
	UnionFind(int n) : par(n), rank(n,0), size(n,1), c(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}
	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }
	int merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return -1; else --c;
		if (rank[i] > rank[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rank[i] == rank[j]) rank[j]++;
		return j;
	}
};

struct S{int i, j, n;};
int main(){
	int n; cin >> n;
	UnionFind uf(n);
	vector<int> root(1e6+1, -1);
	vector<S> ans;
	for(int i = 0; i < n; ++i){
		int m; cin >> m;
		while(m--){
			int x; cin >> x;
			if(root[x] == -1) root[x] = i;
			else {
				if(!uf.same(i, root[x])){
					uf.merge(i, root[x]);
					ans.push_back({i, root[x], x});
				}
			}
		}
	}
	if(ans.size() == n-1)
		for(auto p : ans) cout << p.i+1 << ' ' << p.j+1 << ' ' << p.n << endl;
	else cout << "impossible" << endl;
}
