#include <bits/stdc++.h>
#include "validate.h"
using namespace std;
using ll = long long;
using vl = vector<ll>;
#define sz(c) ll((c).size())
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = ll(b) - 1; i >= (a); i--)

typedef struct node{
  ll left = 0;
  ll right = 0;
  bool chosen = false;
} node;

bool check_avl(node* nodes, ll start, ll &depth) {
  if(start == 0 || !nodes[start].chosen) {
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



int main(int argc, char **argv) {
  init_io(argc,argv);

  ll n, k;
  judge_in >> n >> k;
  node *nodes = new node[n + 1];

  ll root = -1;
  for(int i = 1; i < n + 1; i++) {
    ll father = -1;
    judge_in >> father;
    if(father == -1){
      root = i;
    } else {
      if(father < i) {
        nodes[father].right = i;
      } else {
        nodes[father].left = i;
      }
    }
  }

  string a_ans, j_ans;
  char foo;
  judge_ans >> j_ans;
  if(!( author_out >> a_ans)) wrong_answer("Less output than expected.\n");
  if(author_out >> foo) wrong_answer("More output than expected.\n");

  // sanity check jury answer
  if(j_ans.size() != n){
	judge_error("Jury solution does not have length n.");
  }
  if(count(begin(j_ans), end(j_ans), '1') != k){
	judge_error("Jury solution does not keep the right number of nodes.");
  }
  ll depth = 0;
  for(int i = 0; i < n; i++) {
    nodes[i+1].chosen = (j_ans[i] == '1');
  }
  if(!check_avl(nodes, root, depth)) {
    judge_error("No AVL tree as judge solution.\n");
  }

  //quick accept
  if(a_ans == j_ans) accept();
  if(a_ans.size() != n) {
    wrong_answer("Not enough characters in output.\n");
    return 0;
  }
  if(count(begin(a_ans), end(a_ans), '1') != k){
	wrong_answer("Not the right number of nodes.\n");
  }

  depth = 0;
  for(int i = 0; i < n; i++) {
    nodes[i+1].chosen = (a_ans[i] == '1');
  }
  if(!check_avl(nodes, root, depth)) {
    wrong_answer("No AVL tree as answer.\n");
  }
  if(a_ans.compare(j_ans) < 0) wrong_answer("Suboptimal answer.\n");
  
  judge_error("Given solution better than judge solution.\n");
}
