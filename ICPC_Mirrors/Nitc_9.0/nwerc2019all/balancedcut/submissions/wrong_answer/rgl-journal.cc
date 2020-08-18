#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T> struct PersistentVector{
  private:
    vector<pair<int,T>> history;
    vector<T> v;
  public:
    typename vector<T>::const_iterator begin(){return v.begin();}
    typename vector<T>::const_iterator end(){return v.end();}
    void assign(size_t const n,T const &x){v.assign(n,x); history.clear();}
    T const operator[](size_t i){return v[i];}
    void operator()(size_t i,T const &nv){if (nv!=v[i]){history.emplace_back(i,v[i]); v[i]=nv;}}
    size_t checkpoint()const{return history.size();}
    void rewind(size_t to){
      while (history.size()>to){
        v[history.back().first]=history.back().second;
        history.pop_back();
      }
    }
};

int64_t available=0;
PersistentVector<bool> e;
PersistentVector<int> h;
vector<int> p,l,r;
vector<vector<int>> req;

void establish(int x){
  for (int c: {l[x],r[x]}) if (~c) establish(c);
  req[x]={0,1}; if ((~l[x]) or (~r[x])) req[x].push_back(2);
  if ((!~l[x]) or (!~r[x])) return;
  for (int d=3; req[x].back()!=(1<<29); d++){
    req[x].push_back(1<<29);
    if (req[l[x]].size()>d-1 and req[r[x]].size()>d-2) req[x][d]=min(req[x][d],1+req[l[x]][d-1]+req[r[x]][d-2]);
    if (req[l[x]].size()>d-2 and req[r[x]].size()>d-1) req[x][d]=min(req[x][d],1+req[l[x]][d-2]+req[r[x]][d-1]);
  }
  req[x].pop_back();
}

bool avl_condition(int x){
  int hl=~l[x]?h[l[x]]:0;
  int hr=~r[x]?h[r[x]]:0;
  bool ok=min(hl,hr)>=h[x]-2 and max(hl,hr)==h[x]-1;
  if (not ok){
    cerr<<"child heights for "<<x<<" (h="<<h[x]<<") are "<<hl<<" and "<<hr<<endl;
  }
  return ok;
}

bool insert(int x,int plen=1,int from=-2){
  if (x==-1) return available>=0;
  if (from==-2) plen=max(plen,h[x]);

  // Make node exist.
  if (not e[x]){
    if (req[x].size()<=h[x]) return false;
    available+=req[x][h[x]];
    e(x,true);
    available-=1;
  }

  // Make node appropriately tall.
  h(x,max(h[x],plen));

  // When we create a node requiring height H:
  // - all nodes to the left have already been created.
  // - new nodes to the right may still make the overall tree taller.
  // - one node must have height H-2 or H-1
  // - one node must have height H-1

  // If we didn't come from the right node, make it the right height.
  if (r[x]!=-1 and not e[r[x]]){
    int hl=(l[x]!=-1? h[l[x]]: 0);
    bool longer=(hl<=h[x]-2);
    if (req[r[x]].size()<=h[r[x]]) return false; available+=req[r[x]][h[r[x]]];
    h(r[x],max(0,h[x]-(longer?1:2)));
    if (req[r[x]].size()<=h[r[x]]) return false; available-=req[r[x]][h[r[x]]];
  }

  // Make sure the left node is still tall enough.
  if (r[x]!=-1 and e[r[x]]){
    if (not avl_condition(x)){
      return false;
    }
  }

  // Insert parent.
  return insert(p[x],plen+1,x);
}

int main(){
  ios::sync_with_stdio(false);

  int n,root=-1; cin>>n>>available;
  p.assign(n,-1); l=r=p; h.assign(n,0); req.resize(n); e.assign(n,false);
  for (int i=0; i<n; i++){
    cin>>p[i]; if (~(p[i]--)) (p[i]<i?r:l)[p[i]]=i; else root=i, p[i]=-1;
  }

  establish(root);
  for (int i=0; i<n; i++){
    size_t je=e.checkpoint();
    size_t jh=h.checkpoint();
    int old_available=available;
    if (not insert(i)){
      e.rewind(je);
      h.rewind(jh);
      available=old_available;
    }
  }

  for (auto i: e) cout<<i; cout<<endl;
}
