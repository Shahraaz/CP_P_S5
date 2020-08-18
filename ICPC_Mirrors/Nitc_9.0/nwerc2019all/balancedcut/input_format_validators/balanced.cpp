#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define MAX_SIZE 500000

typedef struct node{
  ll left = 0;
  ll right = 0;
} node;

bool check_avl(node* nodes, ll start, ll &depth) {
  if(start == 0) {
    depth = 0;
    return true;
  }
  ll d1, d2;
  bool is_avl = check_avl(nodes,nodes[start].left,d1);
  is_avl &= check_avl(nodes,nodes[start].right,d2);
  depth = max(d1 + 1,d2 + 1);
  if(!is_avl || abs(d1-d2) > 1) return false;

  return true;
}

int main() {

  ll n, k;

  if(!(cin >> n >> k))
    exit(43);

  if(n < 2 || MAX_SIZE < n)
    exit(43);

  if(k < 1 || k >= n)
    exit(43);

  node *nodes = new node[n + 1];

  ll root = -1;
  for(int i = 1; i < n + 1; i++) {
    ll father = -1;
    if(!(cin >> father) || father < -2 || father == 0 || n < father) {
      cerr << i << ": Father out of range or failed to read father " << father << endl;
      delete[] nodes;
      exit(43);
    }
    if(father == -1){
      if(root != -1) {
        cerr << i << ": Already root: " << root << endl;
        delete[] nodes;
        exit(43);
      }
      root = i;
    } else {
      if(father == i) {
        delete[] nodes;
        cerr << i << ": own father " << father << endl;
        exit(43);
      }
      if(father < i) {
        if(nodes[father].left != 0) {
          cerr <<  i << ": Father " << father << " already has child " << nodes[father].left << endl;
          delete[] nodes;
          exit(43);
        }
        nodes[father].left = i;
      } else {
        if(nodes[father].right != 0) {
          cerr <<  i << ": Father " << father << " already has child " << nodes[father].right << endl;
          delete[] nodes;
          exit(43);
        }
        nodes[father].right = i;
      }
    }
  }


  char foo = '\0';
  bool is_avl = false;
  ll depth = 0;
  if(!(cin >> foo) && root != -1) {
    is_avl = check_avl(nodes, root, depth);
  }
  delete[] nodes;
  
  if(is_avl)
    exit(42);

  cerr << "Failed avl check with root " << root << endl;
  exit(43);
}
