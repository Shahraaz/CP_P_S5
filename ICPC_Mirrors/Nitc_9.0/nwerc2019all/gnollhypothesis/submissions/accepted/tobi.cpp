#include <iostream>
#include <iomanip>
using namespace std;

int n, k, toRemove;
double s[505], newS[505], cumProb;

int main() {
	cin >> n >> k;
	toRemove = n-k;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		cumProb = (double) k/n;
		newS[i] += cumProb*s[i];
		for (int alreadyRemoved = 0; alreadyRemoved < toRemove; alreadyRemoved++) {
			cumProb *= (double)(toRemove-alreadyRemoved)/(n-alreadyRemoved-1);
			newS[i] += cumProb * s[(i-alreadyRemoved-1+n)%n];
		}
		cout << fixed << setprecision(20) << newS[i] << " ";
	}
	cout << endl;
}
