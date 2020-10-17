#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int const MAX_N = 500;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(2, MAX_N, "n");
    inf.readEoln();
    vector<vector<int>> count(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
    	string line = inf.readLine(format("[0-9]{%d}", n), format("g[%d]", i + 1));
    	for (int j = 0; j < line.size(); j++) {
    		count[i][j] = line[j] - '0';
    		ensuref(i < j || count[i][j] == 0, "Elements under main diagonal must be zero, but a[%d][%d] = %d", i + 1, j + 1, count[i][j]);
    	}
    }

    for (int i = 0; i < n; i++) {
    	for (int j = i + 1; j < n; j++) {
    		if (count[i][j] != 0) {
    			ensuref(count[i][j] == 1, "Failed while decoding the number of paths: forced to have %d edges %d -> %d", count[i][j], i + 1, j + 1);
    			for (int k = j + 1; k < n; k++) {
    				count[i][k] = (count[i][k] + 10 - count[j][k]) % 10;
    			}
    		}
    	}
    }

    inf.readEof();
}