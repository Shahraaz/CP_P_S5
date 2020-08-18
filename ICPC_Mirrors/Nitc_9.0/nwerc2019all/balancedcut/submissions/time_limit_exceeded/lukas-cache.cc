// Solution by lukasP (Lukáš Poláček)
// Optimized for better cache locality. Node data is grouped in a struct.
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

const int kEmpty = -1;

struct Node {
  int8_t height = 0;
  int8_t depth = 0;
  int8_t cur_depth = -1;
  std::array<int, 2> sons = {-1, -1};
  int parent = -1;
};

std::vector<Node> nodes;

inline bool ok_depth(int node, int8_t h) {
  int8_t d = node == kEmpty ? 0 : nodes[node].depth;
  return d >= h;
}

void calculate_depth(int node, int8_t h) {
  nodes[node].depth = nodes[node].height = h;
  for (int son : nodes[node].sons)
    if (son != kEmpty) {
      calculate_depth(son, h + 1);
      nodes[node].depth = std::max(nodes[son].depth, nodes[node].depth);
    }
}

std::vector<std::pair<int, int>> old_depth;
bool add(int node, int8_t goal_depth, int* available) {
  if (node == kEmpty) return true;
  if (nodes[node].depth < goal_depth) return false;
  if (nodes[node].cur_depth >= goal_depth || nodes[node].height > goal_depth) return true;

  const int& left = nodes[node].sons[0];
  const int& right = nodes[node].sons[1];
  int8_t left_depth = goal_depth;
  int8_t right_depth = goal_depth - 1;
  if (!ok_depth(left, left_depth)) {
    left_depth = goal_depth - 1;
    right_depth = goal_depth;
  }

  if (nodes[node].cur_depth == -1) {
    if (*available == 0) {
      return false;
    }
    --*available;
  }
  old_depth.emplace_back(node, nodes[node].cur_depth);
  nodes[node].cur_depth = goal_depth;

  bool can_left = add(left, left_depth, available);
  return can_left && add(right, right_depth, available);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  nodes.resize(n);

  int root = -1;
  rep(i, 0, n) {
    int f;
    scanf("%d", &f);
    nodes[i].parent = --f;
    if (f < 0) {
      root = i;
      continue;
    }
    nodes[f].sons[static_cast<int>(f < i)] = i;
  }
  calculate_depth(root, 0);

  rep(i, 0, n) {
    old_depth.clear();
    int available = k;
    bool success = true;
    for (int cur = i; success && cur >= 0; cur = nodes[cur].parent) {
      if (!add(cur, nodes[i].height, &available)) {
        success = false;
      }
    }
    if (!success || available < 0) {
      for (const auto& p : old_depth) {
        nodes[p.first].cur_depth = p.second;
      }
    } else {
      k = available;
    }
  }

  std::string res(n, '0');
  rep(i, 0, n) if (nodes[i].cur_depth >= 0) { res[i] = '1'; }
  std::cout << res << std::endl;
}
