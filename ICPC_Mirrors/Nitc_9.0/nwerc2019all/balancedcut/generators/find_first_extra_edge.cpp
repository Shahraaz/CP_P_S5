#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

// First create a base_tree of size n-1 and k=n-1 using gen-anti-quadratic.py:
// python2 gen-anti-quadratic.py 499999 > base_tree.in
// and make sure that extra_layer is set to false.
//
// Now this c++ solution will find the leftmost position where it can not add an
// extra edge.


vector<int> p, l, r, height, depth, t;
vector<bool> phantom;

vector<bool> take;
int k, maxd=1000;
struct S{int len, delta;};
vector<S> forced_lengths{{0,0}};

int height_dfs(int u){
	if(phantom[u]) return 0;
	height[u] = 1;
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
		assert(!phantom[u]);
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

	auto count = t[forced_lengths.back().len] - t[forced_lengths.back().len-1] - forced_lengths.back().delta;

	if(phantom[u]){
		// Would adding this node violate the AVL property?
		bool avl_ok = true;
		int v = u;
		while(p[v] != -1){
			int par = p[v];
			int sibling = l[par] + r[par] - v;
			assert(sibling != -1);
			if(height[v] < height[sibling])
				break; // success!
			if(height[v] > height[sibling]){
				avl_ok = false;
				break; // failure
			}
			v = p[v];
		}

		if(!avl_ok){
		   	cerr << "AVL failure take node " << u << " with parent " << p[u] << " and depth " << depth[u] << " with childs " << l[p[u]] << " and " << r[p[u]] << endl;
		} else if(count <= k){
		   	cerr << "possible to take node " << u << " with parent " << p[u] << " and depth " << depth[u] << " with childs " << l[p[u]] << " and " << r[p[u]] << endl;
		}
		else {
		   	cerr << "NOT possible to take node " << u << " with parent " << p[u] << " and depth " << depth[u] << " with childs " << l[p[u]] << " and " << r[p[u]] << endl;
			assert(false);
		}
		unwind();
		return h;
	}

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
		cerr << "TAKE: " << u << endl;
		if(l[u] != -1)
			h = max(h, 1+dfs(l[u], 0, true));
		if(r[u] != -1){
			auto added = h > 1 ? t[h-1] - t[h-2] : 0;
			forced_lengths.back().delta += added;
			h = max(h, 1+dfs(r[u], max(h-2, 0), h==1));
			forced_lengths.back().delta -= added;
		}
	} else {
		maxd = depth[u] - 1;
		cerr << "DROP: " << u << " : " << count << "  " << k << endl;
	}

	unwind();
	return h;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> k;
	p.assign(2*n, -1);
	l.assign(2*n, -1);
	r.assign(2*n, -1);
	height.assign(2*n, -1);
	depth.assign(2*n, -1);
	take.assign(2*n, false);
	phantom.assign(2*n, false);
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

	// Use nodes n ... to create phantom childs.
	int ph = n-1;
	for(int i = 0; i < n; ++i){
		if(l[i] == -1){
			l[i] = ++ph;
			phantom[ph] = true;
			p[ph] = i;
		}
		if(r[i] == -1){
			r[i] = ++ph;
			phantom[ph] = true;
			p[ph] = i;
		}
	}

	height_dfs(root);

	t.assign(height[root]+2, 0);
	t[0] = 0;
	t[1] = 1;
	for(int i = 2; i < t.size(); ++i) t[i] = t[i-1] + t[i-2] + 1;

	dfs(root, 0, false);

	//for(int i = 0; i < n; ++i) cout << take[i];
	//cout << endl;
}
