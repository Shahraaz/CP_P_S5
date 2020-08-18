// Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

const int kEmpty = -1;

std::vector<std::array<int, 2>> sons;
std::vector<bool> chosen;
std::vector<int> height;
void calculate_height(int node, int h) {
  if (node == kEmpty) return;
  height[node] = h;
  calculate_height(sons[node][0], h + 1);
  calculate_height(sons[node][1], h + 1);
}

void go(int node, int max_height, int * remove) {
  if (node == kEmpty) {
    return;
  }
  const int & left = sons[node][0];
  const int & right = sons[node][1];
  go(right, max_height - 1, remove);
  go(left, max_height, remove);

  if (*remove > 0 && max_height < height[node]) {
    --*remove;
  } else {
    chosen[node] = true;
  }
}

void print_tree() {
  for(int i = 0; i < chosen.size(); i++) printf("%d", static_cast<int>(chosen[i]));
  printf("\n");
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  sons.resize(n);
  chosen.assign(n, false);
  rep(i, 0, n) { sons[i][0] = sons[i][1] = kEmpty; }

  int root = -1;
  rep(i, 0, n) {
    int f;
    scanf("%d", &f);
    if (f == -1) {
      root = i;
    }
    --f;
    sons[f][static_cast<int>(f < i)] = i;
  }
  height = std::vector<int>(n, 0);
  calculate_height(root, 0);
  int max_height = *std::max_element(height.begin(), height.end());

  int remove = n-k;
  go(root, max_height, &remove);
  if (remove == 0) {
    print_tree();
    return 0;
  }
  chosen.assign(n, false);
  remove = n-k;
  go(root, max_height - 1, &remove);
  print_tree();
}
