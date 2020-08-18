#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

// Converted version of the same python version. See that one for some comments.

vector<int> p, l, r, height, depth, t;

vector<bool> take;
int k, maxd=1000;
struct S{int len, delta;};
vector<S> forced_lengths{{0,0}};

int max_depth = 0;
bool found_max_depth = false;
int total_needed = 0;

int height_dfs(int u){
	height[u] = 1;
	max_depth = max(max_depth, depth[u]);
	if(l[u] != -1){
		depth[l[u]] = depth[u]+1;
		height[u] = max(height[u], height_dfs(l[u]) + 1);
	}
	if(r[u] != -1){
		depth[r[u]] = depth[u]+1;
		height[u] = max(height[u], height_dfs(r[u]) + 1);
	}
	return height[u];
}


int dfs(int u, int h, bool consecutive){
	if(h==0 and depth[u] > maxd) return 0;

	if(consecutive)
		forced_lengths.back().len += 1;
	else
		forced_lengths.push_back({1, 0});

	auto unwind = [&]{
	   	if(--forced_lengths.back().len == 0)
			forced_lengths.pop_back();
	};

	if(h > 0){
		take[u] = true;
		int lh = h-1, rh = h-2;
		if(h > 1 and (l[u] == -1 or height[l[u]] < lh)) swap(lh, rh);

		if(l[u] != -1)
			h = max(h, 1+dfs(l[u], lh, lh==h-1));
		rh = max(rh, max(h-2, 0));
		if(r[u] != -1){
			auto added = h > 1 ? t[h-1] - t[h-2] : 0;
			forced_lengths.back().delta += added;
			h = max(h, 1+dfs(r[u], rh, rh==h-1));
			forced_lengths.back().delta -= added;
		}
		unwind();
		return h;
	}
	if(found_max_depth){
		unwind();
	   	return h;
	}

	auto count = t[forced_lengths.back().len] - t[forced_lengths.back().len-1] - forced_lengths.back().delta;
	k += count;
	total_needed += count;
	if(depth[u] == max_depth)
		found_max_depth = true;
	if(count <= k){
		if(forced_lengths.size() > 1){
			auto x = forced_lengths.back();
			forced_lengths.pop_back();
			forced_lengths.back().len += x.len;
			forced_lengths.back().delta += x.delta;
		}
		take[u] = true;
		k -= count;
		h = 1;
		if(l[u] != -1)
			h = max(h, 1+dfs(l[u], 0, true));
		if(r[u] != -1){
			auto added = h > 1 ? t[h-1] - t[h-2] : 0;
			forced_lengths.back().delta += added;
			h = max(h, 1+dfs(r[u], max(h-2, 0), h==1));
			forced_lengths.back().delta -= added;
		}
	} else
		maxd = depth[u] - 1;

	unwind();
	return h;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> k;
	k = 0;
	p.assign(n, -1);
	l.assign(n, -1);
	r.assign(n, -1);
	height.assign(n, -1);
	depth.assign(n, -1);
	take.assign(n, false);
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
	height_dfs(root);

	t.assign(height[root]+2, 0);
	t[0] = 0;
	t[1] = 1;
	for(int i = 2; i < t.size(); ++i) t[i] = t[i-1] + t[i-2] + 1;

	dfs(root, 0, false);

	cerr << "max depth: " << max_depth << endl;
	cerr << "found max depth: " << found_max_depth << endl;
	cerr << "K needed: " << total_needed << endl;
}
