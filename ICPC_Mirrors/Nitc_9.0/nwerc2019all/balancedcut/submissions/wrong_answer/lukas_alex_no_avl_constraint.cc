// Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

using namespace std;

const int kEmpty = -1;

std::vector<std::array<int, 2>> sons;
std::vector<int> height;
std::vector<bool> chosen;
void calculate_height(int node, int h) {
  if (node == kEmpty) return;
  height[node] = h;
  calculate_height(sons[node][0], h + 1);
  calculate_height(sons[node][1], h + 1);
}

int64_t remove_max_height(int node, int max_height) {
  if(node == kEmpty) return 0;
  const int & left = sons[node][0];
  const int & right = sons[node][1];
  int res = 0;
  res += remove_max_height(right, max_height);
  res += remove_max_height(left, max_height);
  if(height[node] > max_height - 1) {
    sons[node][0] = kEmpty;
    sons[node][1] = kEmpty;
  }
  if(height[node] > max_height) {
    //cerr << "Snipped " << node + 1 << endl;
    return 1 + res;
  }
  return res;
}
void go(int node, int max_height, int * remove) {
  if (node == kEmpty) {
    return;
  }
  int64_t res = 0;
  const int & left = sons[node][0];
  const int & right = sons[node][1];
  go(right, max_height - 1, remove);
  go(left, max_height, remove);

  if (*remove > 0 && max_height < height[node])
    --*remove;
  else
    chosen[node] = true;
}

int compare(std::vector<bool> &best) {
  std::pair<std::vector<bool>::iterator, std::vector<bool>::iterator> mis;
  mis = std::mismatch(best.begin(), best.end(), chosen.begin());
  if(mis.first == best.end()) return 0;
  if(*mis.first == true) return -1;
  return 1;
}

void print_tree(std::vector<bool> &tree) {
  for(int i = 0; i < tree.size(); i++) printf("%d", static_cast<int>(tree[i]));
  printf("\n");
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  sons.resize(n);
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
  
  int current_remove = n - k;
  std::vector<bool> best(n, false);
  while(current_remove >= 0) {
    int remove = current_remove;
    chosen.assign(n, false);
    go(root, max_height, &remove);
    if(remove == 0 && compare(best) > 0)
      best = chosen;
    current_remove -= remove_max_height(root, --max_height);
  }
  print_tree(best);
}
