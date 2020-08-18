#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

int main(){
	long long s, d, t;
	cin >> s >> d >> t;
	int n; cin >> n;
	vector<pair<int, int>> as(n+2);
	as[0] = {0,0};
	for(int i = 1; i <= n; ++i) cin >> as[i].first >> as[i].second;
	as[n+1] = {s,s};

	long long delta = 0;
	for(int i = 1; i <= n+1; ++i){
		as[i].first -= delta;
		as[i].second -= delta;
		if(i > 0 and as[i].first - as[i-1].second >= 3*d){
			auto len = as[i].first - as[i-1].second;
			int jumps = (len - 2*d)/d;
			delta += jumps * d;
			as[i].first -= jumps*d;
			as[i].second -= jumps*d;
		}
	}
	s -= delta;
	long long ans = min(delta/d * t, delta);

	// test if interval [x, y] is island-free
	auto test = [&](int x, int y){
		if(x < 0 or y > s) return false;
		auto it = upper_bound(begin(as), end(as), pair<int,int>{x, x});
		auto v1 = it == as.end() or it->first >= y;
		auto v2 = it == as.begin() or prev(it)->second <= x;
		return v1 and v2;
	};

	map<int, long long> points;
	for(auto q = 0; q <= s and test(q,q); q += d) points.insert({q, 1e18});
	points.insert({s, 1e18});
	for(auto [x, y] : as){
		for(auto p : {x, y}){
			for(auto q = p-d; q >= 0 and test(q,q); q -= d) points.insert({q, 1e18});
			for(auto q = p; q <= s and test(q,q); q += d) points.insert({q, 1e18});
		}
	}
	points[0] = 0;

	for(auto it = next(begin(points)); it != end(points); ++it){
		// Remove points we don't care about anymore.
		while(begin(points)->first < it->first - d)
			points.erase(begin(points));	

		assert(it != begin(points));

		// Either just from the first point or surf from the last if possible.
		it->second = begin(points)->second + t;
		if(test(prev(it)->first, it->first))
			it->second = min(it->second, prev(it)->second + (it->first - prev(it)->first));
	}

	cout << ans + points[s] << endl;
}
