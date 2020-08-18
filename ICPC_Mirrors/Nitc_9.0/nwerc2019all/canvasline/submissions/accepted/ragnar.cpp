#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	vector<pair<int, int>> cs(n);
	for(auto &c : cs) cin >> c.first >> c.second;
	int p; cin >> p;
	vector<int> xs(p);
	for(auto &x : xs) cin >> x;

	// For each canvas, count the pegs.
	vector<int> counts(n);
	int needed = 0;
	for(int i = 0; i < n; ++i){
		auto [l, r] = cs[i];
		counts[i] = upper_bound(begin(xs), end(xs), r) - lower_bound(begin(xs), end(xs), l);
		if(counts[i] > 2){
			cout << "impossible\n";
			return 0;
		}

		needed += 2 - counts[i];
	}

	set<int> take;

	// merge?
	for(int i = 0; i < n-1; ++i){
		if(cs[i].second != cs[i+1].first) continue;
		if(counts[i] == 2 or counts[i+1] == 2) continue;
		auto it = lower_bound(begin(xs), end(xs), cs[i].second);
		if(it != end(xs) and *it == cs[i].second) continue;
		++counts[i], ++counts[i+1];
		take.insert(cs[i].second);
	}
	
	for(int i = 0; i < n; ++i){
		auto [l, r] = cs[i];
		for(int j = l+1; j < r and counts[i] < 2; ++j){
			auto it = lower_bound(begin(xs), end(xs), j);
			if(it == end(xs) or *it != j){
				++counts[i];
				take.insert(j);
			}
		}
	}

	cout << take.size() << endl;
	for(auto x : take) cout << x << '\n';

}
