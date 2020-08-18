#include <iostream>
#include <deque>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
	int n;
	long long delta_time, remove_time; cin >> n >> delta_time >> remove_time;

	vector<long long> s(n);
	for(auto &x : s) cin >> x;
	vector<long long> idx(n);
	iota(begin(idx), end(idx), 0);
	// Sort by increasing absolute value.
	sort(begin(idx), end(idx), [&](int i, int j){ return abs(s[i]) > abs(s[j]);});

	// Delta all the numbers.
	long long ans = delta_time * (abs(s[idx[0]]) + 1);
	// Delta no numbers, remove all zero's and same-sign pairs.
	{
		long long last = 2e9;
		int remove = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == 0){
			   	++remove;
				continue;
			}
			if(last != 2e9 and s[i] * last > 0)
				++remove;
			last = s[i];
		}
		ans = min(ans, remove_time * remove);
	}

	auto test = [&](int i, int j){ return i>=0 and j < n and not((s[i] * s[j] >= 0) ^ ((j-i)%2==1)); };

	deque<int> taken = {-1, n};
	int remove = 0;
	for(int t = 0; t < n; ++t){
		int index = idx[t];
		if(s[index] == 0) break; // This is already handled above.
		long long delta = t < n-1 ? abs(s[idx[t+1]]) + 1 : 0; 

		auto it = lower_bound(begin(taken), end(taken), index);
		auto next_idx = *it;
		auto prev_idx = *prev(it);

		taken.insert(it, index);

		if(test(prev_idx, next_idx)) --remove;
		if(test(prev_idx, index)) ++remove;
		if(test(index, next_idx)) ++remove;

		ans = min(ans, remove*remove_time + delta * delta_time);
	}

	cout << ans << endl;
}
