#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define pb push_back
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
const bool dbg = false;

/**
* Wrongly assumes that if a number of nodes is available it is always best to
* just choose the highest AVL tree that can be produced with this number of nodes.
**/

typedef struct node {
  ll left = 0;
  ll right = 0;
  bool chosen = false;
} node;

vl trees;


/**
 * Only for assert
 */
bool check_avl(node* nodes, ll start, ll &depth) {
  if(start == 0) {
    depth = 0;
    return true;
  }
  ll d1, d2;
  bool is_avl = check_avl(nodes,nodes[start].left,d1);
  if(!is_avl){
    cerr << start << ": Left side not AVL" << endl;
    return false;
  }
  is_avl &= check_avl(nodes,nodes[start].right,d2);
  if(!is_avl) {
    cerr << start << ": Right side not AVL" << endl;
    return false;
  }
  depth = max(d1 + 1,d2 + 1);
  if(abs(d1-d2) > 1){
    cerr << start << ": Depths differ: " << d1 << " " << d2 << endl;
    return false;
  }

  return true;
}

/**
 * Returns (nodes unused)
 */
ll balance(node* nodes, ll start, ll max_nodes, ll max_depth) {
  assert(start != 0);
  if(dbg)  cerr << "balancing " << start << ": " << max_nodes << " to use; " << max_depth << " to go" << endl;

  if(max_nodes == 0 || max_depth == 0) return max_nodes;
  nodes[start].chosen = true;
  if(max_nodes == 1 || max_depth == 1) {
    nodes[start].left = 0;
    nodes[start].right = 0;
    return max_nodes - 1;
  }
  
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
    nodes[start].right = 0;
    max_nodes = 0;
  }
  else {
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

  // Impossible max depth shouldn't break the algorithm
  ll res = balance(nodes, root, k, 100);
  assert(res == 0);
  
  ll depth;
  assert(check_avl(nodes,root,depth));

  FOR(i,1,n + 1) cout << nodes[i].chosen ? 1 : 0;
  cout <<  endl;

  delete[] nodes;
  return 0;
}
