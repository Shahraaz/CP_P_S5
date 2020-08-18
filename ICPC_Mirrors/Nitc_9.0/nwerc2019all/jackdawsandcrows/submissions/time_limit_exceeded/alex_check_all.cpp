#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
#define mp make_pair
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

#define WILD 1000*1000*1000LL + 1

/**
* This submission is nearly identical to accepted alex.cpp.
* Only difference is that it uses the check function for each
* sensible number of fake accounts
**/


typedef struct node {
  ll val;
  ll prev;
  ll next;
} node;

inline int sign(ll v) {
  return (0 < v) - (v < 0);
}

inline ll abso(ll v) {
  return sign(v) * v;
}

// returns 1 if x % 2 == 0; -1 otherwise
inline int  sign_mod2(ll v) {
  v %= 2;
  return (v == 0) - (v > 0);
}

inline bool is_alternating(vector<node> &nodes, size_t a, size_t b) {
  ll dist = abso(a - b);
  return sign(nodes[a].val * nodes[b].val) == sign_mod2(dist);
}

// this method prepares the vector if 0 is an occuring value
// it returns the number of removals if no fake accounts are created
ll prepare(vector<node> &nodes, ll n) {
  ll last_valid = -1;
  ll removals = 0;
  FOR(i,0,n) {
    if(nodes[i].val == 0) {
      removals++;
      nodes[i].val = WILD;
    } else {
      if(last_valid != -1) {
        // equal signs?
        if(nodes[last_valid].val * nodes[i].val > 0) removals++;
        nodes[last_valid].next = i;
        nodes[i].prev = last_valid;
      } else {
        nodes[i].prev = -1;
        // update management
        nodes[n].prev = i;
      }
      last_valid = i;
    }
  }
  if(last_valid != -1) {
    nodes[last_valid].next = -1;
    // update management
    nodes[n].next = last_valid;
  } else {
    nodes[n].next = -1;
    nodes[n].prev = -1;
  }
  return removals;
}

// this method calculates the number of removals for the current sequence
ll check(vector<node> &nodes, ll n) {
  ll removals = 0;
  for(int i = nodes[n].prev; i < nodes[n].next; i = nodes[i].next) {
    if(!is_alternating(nodes, i, nodes[i].next)) removals++;
  }
  return removals;
}

// updates the sequence making index i a wildcard
// returns the change in removal
ll update(vector<node> &nodes, ll n, size_t i) {
  ll change = 0;
  if(nodes[i].prev != -1) {
    if(!is_alternating(nodes, i, nodes[i].prev)) change -= 1;
    nodes[nodes[i].prev].next = nodes[i].next;
  }
  if(nodes[i].next != -1) {
    if(!is_alternating(nodes, i, nodes[i].next)) change -= 1;
    nodes[nodes[i].next].prev = nodes[i].prev;
  }
  if(nodes[i].prev != -1 && nodes[i].next != -1 && !is_alternating(nodes, nodes[i].prev, nodes[i].next)) change += 1;
  nodes[i].val = WILD;
  // update management
  if(nodes[n].prev == i) nodes[n].prev = nodes[i].next;
  if(nodes[n].next == i) nodes[n].next = nodes[i].prev;
  return change;
}

int main() {
  ll n,x,y;
  cin >> n >> x >> y;
  vector<node> nodes(n + 1);
  vector<pll> vals(n);
  FOR(i,0,n) {
    ll val;
    cin >> val;
    vals[i] = mp(abso(val), i);
    nodes[i].val = val;
    nodes[i].prev = i - 1;
    nodes[i].next = i + 1;
  }
  nodes[n-1].next = -1;
  // use the n+1th node as management for first and last non-wildcard
  nodes[n].prev = 0;
  nodes[n].next = n - 1;

  sort(vals.begin(), vals.end());
  
  ll best = oo;
  ll index = 0;
  ll current_removal = 0;
  if(vals[0].xx == 0) {
    best = prepare(nodes, n) * y;
    current_removal = check(nodes, n);
    best = min(best, x * 1 + y * current_removal);
    while(index < n && vals[index].xx == 0) index++;
  } else {
    current_removal = check(nodes, n);
    best = y * current_removal;
  }

  while(index < n) {
    ll fakes = vals[index].xx;
    while(index < n && vals[index].xx == fakes) {
      update(nodes, n, vals[index].yy);
      index++;
    }
    current_removal = check(nodes, n);
    best = min(best, x * (fakes + 1) + y * current_removal);
  }
  cout << best << endl;
  return 0;
}
