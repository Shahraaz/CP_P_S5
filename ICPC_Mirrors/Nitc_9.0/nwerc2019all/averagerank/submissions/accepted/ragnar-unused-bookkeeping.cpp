#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
	int n, W; cin >> n >> W;
	vector<vector<int>> ws(W);
	for(auto &x : ws){
		int k; cin >> k;
		x.resize(k);
		for(auto &y : x) cin >> y, --y;
	}
	
	// For each score a list of (week, rank) pairs. At most 2e6 pairs in total.
	struct S{
		long long week, rank;
		// The total rank if you're in this group from the start to just before
		// the week w event.
		long long totalrank;
	};

	// Initially everybody starts at score 0 in week 0 with rank 1.
	vector<vector<S>> score_rank(1000001, {S{0, 1, 0}});


	vector<int> scores(n, 0);
	vector<long long> total_rank(n, 0);

	for(int w = 0; w < W; ++w){
		for(auto p : ws[w]){
			// Person p gets a point.
			auto &s = scores[p];
			// Rank of people with old score goes up by one.
			auto &last = score_rank[s].back();
			auto &next = score_rank[s+1].back();
			auto s_total_rank = last.totalrank + (w-last.week) * last.rank;
			auto next_s_total_rank = next.totalrank + (w-next.week) * next.rank;
			score_rank[s].push_back({w, last.rank + 1, s_total_rank});
			++s;

			// Follow the score progression for this person:
			total_rank[p] += s_total_rank;
			total_rank[p] -= next_s_total_rank;
		}
	}

	for(int p = 0; p < n; ++p){
		auto& last = score_rank[scores[p]].back();
		total_rank[p] += last.totalrank + (W - last.week) * last.rank;
	}

	for(auto tr : total_rank)
		cout << setprecision(10) << fixed << tr / (double) W << endl;

}
