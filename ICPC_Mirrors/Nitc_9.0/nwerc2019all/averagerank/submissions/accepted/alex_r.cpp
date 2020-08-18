#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)


vector<ll> segtree;
vector<ll> segtree_cur;

int L;

ll query(int id, int f, int t, int F, int T){
    f = max(f,F);
    t = min(t,T);
    if(f>=t)return 0;
    if(f == F && t == T)return segtree[id];
    int id1 = id*2+1;
    int M = F + (T-F)/2;
    return query(id1, f, t,  F, M) + query(id1+1, f,t,M,T) + (t-f) * segtree_cur[id];
}
ll query(int f, int t){
    ll res = query(0,f,t,0,L);
    return res;
}


void update(int id, int f, int t, int F, int T, int v){
    f = max(f,F);
    t = min(t,T);
    if(f>=t)return;
    if(f == F && t == T){
        segtree_cur[id] += v;
        segtree[id] += v * (T-F);
    } else {
        int id1 = id*2+1;
        int M = F + (T-F)/2;
        update(id1, f, t,  F, M, v);
        update(id1+1, f,t,M,T,v);
        segtree[id] = segtree_cur[id] * (T-F) + segtree[id1] + segtree[id1+1];
    }
}
void update(int f, int t, int v){
    update(0,f,t,0,L,v);
}

void clear(int id){
    bool fin = (segtree[id] == segtree_cur[id]);
    segtree[id] = segtree_cur[id] = 0;
    if(!fin){
        clear(id*2+1);
        clear(id*2+2);
    }
}
void clear(){
    clear(0);
}

vector<int> pts;
vector<vector<pair<int,int> > > users_reach_points;
vector<int> previous;
vector<ll> results;
int main(){
    int U,W;
    cin >> U >> W;
    L = W + 1;
    segtree = vector<ll>(W*5+5);
    segtree_cur = vector<ll>(W*5+5);
    pts = vector<int>(U);
    previous = vector<int>(U);
    results = vector<ll>(U);
    users_reach_points = vector<vector<pair<int,int> > >((int)1.1e6);
    FOR(w,0,W){
        int K;
        cin >> K;
        FOR(k,0,K){
            int u;
            cin >> u;
            int p = ++pts[--u];
            users_reach_points[p].push_back(make_pair(u,w));
        }
    }
    FOR(u,0,U)users_reach_points[++pts[u]].push_back(make_pair(u,W));
    FOR(p,1,((int)users_reach_points.size())){
        clear();
        if(users_reach_points[p].empty())break;
        int done = 0;
        for(auto it: users_reach_points[p]){
            while(users_reach_points[p][done].second != it.second){
                update(users_reach_points[p][done++].second, W,1);
            }
            results[it.first] += query(previous[it.first], it.second);
            previous[it.first] = it.second;
        }
    }
    FOR(u,0,U){
        printf("%.9lf\n", 1.0 + (results[u] / (double) W));
    }
    return 0;
}
