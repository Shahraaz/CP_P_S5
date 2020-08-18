#include <iostream>
#include <iomanip>
using namespace std;

int n, weeks, k, c, points[1000005], lastUpdate[1000005];
long long sumRanks[1000005], groupSum[1000005], rnk[1000005], joinSum[1000005];

#define UPDATE(group, week) groupSum[group] += rnk[group] * (week - lastUpdate[group]), lastUpdate[group] = week
void leaveGroup(int week, int candidate) {
	int group = points[candidate];
	UPDATE(group, week);
	rnk[group]++;
	sumRanks[candidate] += groupSum[group] - joinSum[candidate];
}

void joinGroup(int week, int candidate) {
	int group = ++points[candidate];
	UPDATE(group, week);
	joinSum[candidate] = groupSum[group];
}

int main() {
	cin >> n >> weeks;
	for (int week = 0; week < weeks, cin >> k; week++) for (int j = 0; j < k; j++) {
		cin >> c;
		leaveGroup(week, c);
		joinGroup(week, c);
	}
	for (int i = 1; i <= n; i++) leaveGroup(weeks, i);
	for (int i = 1; i <= n; i++) cout << fixed << setprecision(20) << 1+(double)sumRanks[i]/weeks << endl;
}
