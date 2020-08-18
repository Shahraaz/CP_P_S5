// Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

const int kEmpty = -1;

std::vector<std::array<int, 2>> sons;
std::vector<int8_t> height, depth, cur_depth;

bool ok_depth(int node, int8_t h) {
  int8_t d = node == kEmpty ? 0 : depth[node];
  return d >= h;
}

void calculate_depth(int node, int8_t h) {
  depth[node] = height[node] = h;
  for (int son : sons[node])
    if (son != kEmpty) {
      calculate_depth(son, h + 1);
      depth[node] = std::max(depth[son], depth[node]);
    }
}

std::vector<std::pair<int, int>> old_depth;
bool add(int node, int8_t goal_depth, int* available) {
  if (node == kEmpty) return true;
  if (depth[node] < goal_depth) return false;
  if (cur_depth[node] >= goal_depth || height[node] > goal_depth) return true;

  const int& left = sons[node][0];
  const int& right = sons[node][1];
  int8_t left_depth = goal_depth;
  int8_t right_depth = goal_depth - 1;
  if (!ok_depth(left, left_depth)) {
    left_depth = goal_depth - 1;
    right_depth = goal_depth;
  }

  if (cur_depth[node] == -1) {
	// Omitting this makes it go TLE.
	/*
    if (*available == 0) {
      return false;
    }
	*/
    --*available;
  }
  old_depth.emplace_back(node, cur_depth[node]);
  cur_depth[node] = goal_depth;

  bool can_left = add(left, left_depth, available);
  return can_left && add(right, right_depth, available);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  sons.resize(n, {kEmpty, kEmpty});
  std::vector<int> parent(n);

  int root = -1;
  rep(i, 0, n) {
    int f;
    scanf("%d", &f);
    parent[i] = --f;
    if (f < 0) {
      root = i;
      continue;
    }
    sons[f][static_cast<int>(f < i)] = i;
  }
  height.resize(n, 0);
  depth.resize(n, 0);
  cur_depth.resize(n, -1);
  calculate_depth(root, 0);

  rep(i, 0, n) {
    old_depth.clear();
    int available = k;
    bool success = true;
    for (int cur = i; success && cur >= 0; cur = parent[cur]) {
      if (!add(cur, height[i], &available)) {
        success = false;
      }
    }
    if (!success || available < 0) {
      for (const auto& p : old_depth) {
        cur_depth[p.first] = p.second;
      }
    } else {
      k = available;
    }
	if (k == 0) {
		break;
	}
  }

  std::string res(n, '0');
  rep(i, 0, n) if (cur_depth[i] >= 0) { res[i] = '1'; }
  std::cout << res << std::endl;
}
