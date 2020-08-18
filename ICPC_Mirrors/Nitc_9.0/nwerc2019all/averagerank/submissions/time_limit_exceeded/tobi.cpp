#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
using namespace std;

struct rnk {
	set<int> cands;
	rnk *pre, *nxt;
	int pts;
};
rnk* candToRank[300005];
int n, w, k, c;
long long sumRanks[300005];

int main() {
	cin >> n >> w;
	rnk *initial = new rnk();
	for (int i = 1; i <= n; i++) {
		initial->cands.insert(i);
		candToRank[i] = initial;
	}
	for (int i = 0; i < w; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> c;
			if (candToRank[c]->pre != NULL && candToRank[c]->pre->pts == candToRank[c]->pts + 1) {
				candToRank[c]->cands.erase(c);
				candToRank[c] = candToRank[c]->pre;
				candToRank[c]->cands.insert(c);
			} else if (candToRank[c]->cands.size() == 1) {
				candToRank[c]->pts = candToRank[c]->pts + 1;
			} else {
				candToRank[c]->cands.erase(c);
				rnk *tmp = candToRank[c]->pre;
				candToRank[c]->pre = new rnk();
				candToRank[c]->pre->nxt = candToRank[c];
				candToRank[c] = candToRank[c]->pre;
				if (tmp != NULL) tmp->nxt = candToRank[c];
				candToRank[c]->pts = candToRank[c]->nxt->pts + 1;
				candToRank[c]->pre = tmp;
				candToRank[c]->cands.insert(c);
			}
			if (candToRank[c]->nxt != NULL && candToRank[c]->nxt->cands.size() == 0) {
				rnk *tmp = candToRank[c]->nxt;
				candToRank[c]->nxt = tmp->nxt;
				if (candToRank[c]->nxt != NULL) candToRank[c]->nxt->pre = candToRank[c];
				delete tmp;
			}
		}
		int curRank = 1;
		rnk *best = candToRank[1];
		while (best->pre != NULL) best = best->pre;
		int x = 0;
		while (best != NULL) {
			x++;
			for (int p : best->cands) sumRanks[p] += curRank;
			curRank += best->cands.size();
			best = best->nxt;
		}
	}
	for (int i = 1; i <= n; i++) cout << fixed << setprecision(20) << (double)sumRanks[i]/w << endl;
}
