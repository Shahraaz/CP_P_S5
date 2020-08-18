// Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <cstdio>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

struct UF {
  std::vector<int> e;
  UF(int n) : e(n, -1) {}
  bool same_set(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (e[a] > e[b]) std::swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

int main() {
  int n;
  scanf("%d", &n);

  std::unordered_map<int, std::vector<int>> cliques;
  rep(i, 0, n) {
    int m;
    scanf("%d", &m);
    rep(j, 0, m) {
      int d;
      scanf("%d", &d);
      cliques[d].push_back(i);
    }
  }

  UF g(n);
  std::vector<std::tuple<int, int, int>> edges;
  for (const std::pair<int, std::vector<int>>& clique : cliques) {
    int a = clique.second[0];
    rep(i, 1, clique.second.size()) {
      int b = clique.second[i];
      if (!g.same_set(a, b)) {
        g.join(a, b);
        edges.emplace_back(a, b, clique.first);
      }
    }
  }

  if (g.size(0) != n) {
    std::cout << "impossible" << std::endl;
  } else {
    for (const auto& e : edges) {
      std::cout << std::get<0>(e) + 1 << " " << std::get<1>(e) + 1 << " " << std::get<2>(e) << std::endl;
    }
  }
}
