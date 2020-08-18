#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define FOR(i,a,b) for (auto i=(a); i<(b); ++i)
using namespace std;

long long s, d, t, n, a[505], o[505];
unordered_map<long long,long long> dp;

long long left(long long pos) {
	FOR(i, 0, n) if (a[i] <= pos && pos < o[i]) return a[i];
	return pos;
}

long long next(long long pos) {
	FOR(i, 0, n) if (a[i] >= pos) return a[i]; 
	return pos;
}

long long fastForward(long long distance) {
	long long jumps = distance / d;
	long long ret = min((jumps+1)*t, min(jumps*t + distance-jumps*d, distance));
	return ret;
}

long long rec(long long pos) {
	if (pos >= s) return 0;
	auto it = dp.find(pos);
	if (it != dp.end()) return it->second;
	long long best = 505LL*1000000000LL;
	long long nextIsland = next(pos);
	if (pos < nextIsland) best = min(best, fastForward(nextIsland-pos) + rec(nextIsland));
	long long jumpy = (nextIsland-pos)/d;
	if (jumpy > 0) best = min(best, jumpy*t + rec(pos + jumpy*d));
	long long jumpPos = left(pos + d);
	if (jumpPos > nextIsland) best = min(best, t + rec(jumpPos));
	FOR(i, 0, n) {
		long long revJump = a[i] - d;
		if (pos < revJump && revJump < nextIsland) best = min(best, fastForward(revJump-pos) + rec(revJump));
		revJump = o[i] - d;
		if (pos < revJump && revJump < nextIsland) best = min(best, fastForward(revJump-pos) + rec(revJump));
	}
	if (pos + d >= s) best = min(best, t);
	dp.insert(make_pair(pos, best));
	return best;
}

int main() {
	cin >> s >> d >> t >> n;
	FOR(i, 0, n) cin >> a[i] >> o[i];
	a[n] = o[n] = s;
	n++;
	cout << rec(0) << endl;
}
