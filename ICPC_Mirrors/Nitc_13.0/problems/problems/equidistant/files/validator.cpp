#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

const int MAX_N = (int) 2e5;

vector<int> p;

int get(int x) {
	return p[x] == x ? x : (p[x] = get(p[x]));
}

void unite(int x, int y) {
	p[get(x)] = get(y);
}

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, MAX_N, "n");
    inf.readSpace();
    int m = inf.readInt(1, n, "m");
    inf.readEoln();
    p.resize(n);
    for (int i = 0; i < n; i++) {
    	p[i] = i;
    }
    for (int i = 0; i + 1 < n; i++) {
    	int x = inf.readInt(1, n, "v_i") - 1;
    	inf.readSpace();
    	int y = inf.readInt(1, n, "u_i") - 1;
    	inf.readEoln();
    	ensuref(get(x) != get(y), "there is a cycle in the graph");
    	unite(x, y);
    }
    std::vector<int> teams;
    for (int i = 0; i < m; i++) {
    	teams.push_back(inf.readInt(1, n, "team_i"));
    	if (i != m - 1) {
    		inf.readSpace();
    	}
    }
    std::sort(teams.begin(), teams.end());
    for (int i = 0; i + 1 < teams.size(); i++) {
    	ensuref(teams[i] != teams[i + 1], "same cities");
    }
    inf.readEoln();
    inf.readEof();
}