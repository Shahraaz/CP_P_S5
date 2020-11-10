// Author: Ivan Katanic
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

typedef long long llint;

const int MAX = 300100;
const double inf = 1e100;

vector<int> E[MAX];
double d[MAX];
bool visited[MAX];

int visited_neighbours_cnt[MAX];
double visited_neighbours_sum[MAX];

struct cmp {
  bool operator () (const int& x, const int& y) {
    if (d[x] != d[y]) return d[x] < d[y];
    return x < y;
  }
};

set<int, cmp> S;

void recalc(int x) {
  int deg = E[x].size();
  d[x] = (visited_neighbours_sum[x] + deg) / visited_neighbours_cnt[x];
}

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  for (int i = 0; i < N; ++i) {
    d[i] = inf;
  }
  d[N-1] = 0;
  S.insert(N-1);

  while (S.size()) {
    int x = *S.begin();
    S.erase(S.begin());

    visited[x] = true;
    for (int y: E[x]) {
      if (!visited[y]) {
        S.erase(y);

        visited_neighbours_cnt[y]++;
        visited_neighbours_sum[y] += d[x];
        recalc(y);

        S.insert(y);
      }
    }
  }

  printf("%.10lf\n", d[0]);
  return 0;
}


