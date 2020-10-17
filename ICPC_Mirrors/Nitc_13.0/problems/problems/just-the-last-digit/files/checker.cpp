#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;


vector<vector<int>> readMatrix(int n, InStream& inf, int max) {
	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s = inf.readLine();
		if (s.size() != n) {
			inf.quitf(_wa, "Line #%d has wrong length: expected %d, but got %d", i + 1, n, s.size());
		}
		for (int j = 0; j < s.size(); j++) {
			if (s[j] < '0' || s[j] > '0' + max) {
				inf.quitf(_wa,  "Incorrect character on line %d, position %d: %c", i + 1, j + 1, s[j]);
			}
			matrix[i][j] = s[j] - '0';
			if (i >= j && matrix[i][j] != 0) {
				inf.quitf(_wa, "Elements under main diagonal must be zero, but a[%d][%d] = %d", i + 1, j + 1, matrix[i][j]);
			}
		}
	}
	return matrix;
}

pair<int, int> checkGraph(int n, vector<vector<int>>& checkCount, InStream& inf) {
	vector<vector<int>> graph = readMatrix(n, inf, 1);
	vector<vector<int>> realCount(n, vector<int>(n));
	
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (graph[i][j] == 1) {
				realCount[i][j] = (realCount[i][j] + 1) % 10;
				for (int k = j + 1; k < n; k++) {
					realCount[i][k] = (realCount[i][k] + realCount[j][k]) % 10;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (realCount[i][j] != checkCount[i][j]) {
				return {i, j};
			}
		}
	}
	return {-1, -1};
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

	int n = inf.readInt();
	inf.readEoln();
	vector<vector<int>> count = readMatrix(n, inf, 9);
	pair<int, int> ja = checkGraph(n, count, ans);
	pair<int, int> pa = checkGraph(n, count, ouf);
	if (ja.first != -1) {
		quitf(_fail, "Jury's graph doesn't have the correct number of paths between vertices %d and %d", ja.first + 1, ja.second + 1);
	}
	if (pa.first != -1) {
		quitf(_wa, "Participant's graph doesn't have the correct number of paths between vertices %d and %d", pa.first + 1, pa.second + 1);
	}
    quitf(_ok, "n=%d", n);
}