#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

/**
* This submission does the same as alex_amount_eq_min_tree.cpp but
* checks all global depths instead of just the one that fits the minimal
* tree. Breaks when it is better for a subtree to be smaller than the minimal
* AVL tree possible with the amount of nodes available but this subtree does
* not influence the global height of the AVL tree.
**/

typedef struct node {
  ll left = 0;
  ll right = 0;
  bool chosen = false;
} node;

vl trees;

ll get_depth(node* nodes, ll start) {
  if(start == 0)
    return 0;
  return 1 + max(get_depth(nodes, nodes[start].left), get_depth(nodes, nodes[start].right));
}

/**
 * Returns (nodes unused)
 */
ll balance(node* nodes, ll start, ll max_nodes, ll max_depth) {
  if(max_nodes == 0 || max_depth == 0) return max_nodes;
  nodes[start].chosen = true;
  if(max_nodes == 1 || max_depth == 1) return max_nodes - 1;
  
  ll right_tree_avail, left_tree_avail;
  
  // Find AVL-tree just below the next highest optimal AVL-tree
  ll next_ind = 2;
  while(trees[next_ind] <= max_nodes && next_ind <= max_depth) next_ind++;
  next_ind--;

  if(nodes[start].left) {
    left_tree_avail = (max_nodes - 1) - trees[next_ind - 2];
    ll res = balance(nodes, nodes[start].left, left_tree_avail, next_ind - 1);

    // res is between 0 and (max_nodes -1 - trees[next_ind - 2])
    right_tree_avail = trees[next_ind - 2] + res;
  } else {
    right_tree_avail = max_nodes - 1;
  }

  if(right_tree_avail == 0) {
    max_nodes = 0;
  } else {
    if(nodes[start].right) {
      // Allow right side to also be as deep as potential left side
      // Should be impossible to result in way deeper right side since it had to be an AVL tree before
      ll res = balance(nodes, nodes[start].right, right_tree_avail, next_ind - 1);
      max_nodes = res;
    } else {
      max_nodes = right_tree_avail;
    }
  }

  return max_nodes;
}

int main() {
  ios_base::sync_with_stdio(false);

  // generate optimal 'unbalanced' AVL-trees
  trees.pb(0);
  trees.pb(1);
  ll c = 1;
  while(trees[c++] <= 1000LL * 1000LL * 300LL) {
    trees.pb(1 + trees[c - 2] + trees[c - 1]);
  }

  ll n, k, root;
  cin >> n >> k;

  node *nodes = new node[n + 1];

  FOR(i,1,n + 1) {
    ll father;
    cin >> father;
    if(father == -1)
      root = i;
    else {
      if(father > i)
        nodes[father].left = i;
      else
        nodes[father].right = i;
    }
  }

  ll current_depth = get_depth(nodes, root);
  ll res = balance(nodes, root, k, current_depth);
  ostringstream os;
  FOR(i, 1, n+1) {
    os << nodes[i].chosen ? 1 : 0;
    nodes[i].chosen = false;
  }
  string best = os.str();
  while(res == 0) {
    os.str(string());
    FOR(i, 1, n+1){ 
      os << nodes[i].chosen ? 1 : 0;
      nodes[i].chosen = false;
    }
    string cur_str = os.str();
    if(best.compare(cur_str) < 0)
      best.swap(cur_str);
    res = balance(nodes, root, k, --current_depth);
  }

  cout << best << endl;
  delete[] nodes;
  return 0;
}
