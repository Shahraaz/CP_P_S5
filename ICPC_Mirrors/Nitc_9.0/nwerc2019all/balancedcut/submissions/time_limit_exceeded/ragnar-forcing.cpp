#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

vector<int> p, l, r;

vector<vector<int>> forced;

vector<bool> take;
vector<int> added;
int k, s;

bool visit(int u){
	if(take[u]) return true;
	if(s==k) return false;
	for(auto v : forced[u]) if(not visit(v)) return false;
	if(s==k) return false;
	take[u] = true;
	added.push_back(u);
	++s;
	return true;
}

void dfs(int u){
	if(s == k) return;
	added.clear();
	if(not visit(u)){
		s -= added.size();
		for(auto x : added)
			take[x] = false;
		return;
	}
	if(l[u] != -1) dfs(l[u]);
	if(r[u] != -1) dfs(r[u]);
}

int main(){
	int n;
	cin >> n >> k;
	p.assign(n, -1);
	l.assign(n, -1);
	r.assign(n, -1);
	int root;
	for(int i = 0; i < n; ++i){
		int f; cin >> f; --f;
		if(f==-2){
			f = -1;
			root = i;
			continue;
		}
		p[i] = f;
		if(i > f) r[f] = i;
		else l[f] = i;
	}

	int max_depth = 3+1.5*log(n+2)/log(2);
	// O(n * log(n)) size vector
	vector<vector<int>> first(n, vector<int>(max_depth, -1));

	for(int i = 0; i < n; ++i){
		first[i][0] = i;
		int d = 1;
		int u = p[i];
		while(u != -1){
			if(first[u][d] == -1)
				first[u][d] = i;
			++d;
			u = p[u];
		}
	}

	forced.resize(n);
	for(int i = 0; i < n; ++i){
		if(p[i] == -1) continue;
		int d = 1;
		int u = p[i];
		if(u != -1) forced[i].push_back(u);
		while(u != -1){
			if(d > 1){
				auto f = first[r[u]][d-2];
				if(f != -1) forced[i].push_back(f);
			}
			u = p[u];
			++d;
		}
	}

	take.assign(n, false);
	s = 0;
	
	dfs(root);

	for(int i = 0; i < n; ++i) cout << take[i];
	cout << endl;
}
