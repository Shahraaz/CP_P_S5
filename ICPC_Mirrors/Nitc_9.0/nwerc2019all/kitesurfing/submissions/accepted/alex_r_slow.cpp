// O(n^3)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

const int MAXN = 512;
ll x[MAXN][2];
unordered_set<int> positions_s;
ll L,D,T;
int N;
void add_positions(ll p){
    ll pp = p;
    int id = 0;
    while(p <= L){
        while(id < N && x[id][1] < p)++id;
        if(id < N && x[id][0] < p && p < x[id][1])break;
        positions_s.insert(p);
        p += D;
    }
    p = pp;
    id = N-1;
    while(p >= 0){
        while(id >= 0 && x[id][0] > p)--id;
        if(id >= 0 && x[id][0] < p && p < x[id][1])break;
        positions_s.insert(p);
        p -= D;
    }
}
vector<ll> positions;
vector<ll> best;
vector<bool> forbidden;
int main(){
    cin >> L >> D >> T >> N;
    FOR(i,0,N)FOR(j,0,2)cin >> x[i][j];
    ll base_res = 0;
    FOR(i,1,N){
        ll dist = x[i][0] - x[i-1][1];
        ll num = dist / D;
        ll move = max(0ll, num - 2);
        FOR(ii,i,N)FOR(j,0,2)x[ii][j] -= move * D;
        L -= move * D;
        base_res += move * min(D,T);
    }
    {
        ll dist = x[0][0];
        ll num = dist / D;
        ll move = max(0ll, num - 2);
        FOR(ii,0,N)FOR(j,0,2)x[ii][j] -= move * D;
        L -= move * D;
        base_res += move * min(D,T);
    }
    {
        ll dist = L - x[N-1][1];
        ll num = dist / D;
        ll move = max(0ll, num - 2);
        L -= move * D;
        base_res += move * min(D, T);
    }
    cerr << L << " " << D << " " << (L/D) << endl;
    positions_s.clear();
    add_positions(0);
    add_positions(L);
    FOR(i,0,N)FOR(j,0,2)add_positions(x[i][j]);
    positions=vector<ll>(all(positions_s));
    sort(all(positions));
    int K = positions.size();
    best = vector<ll>(K,1ll<<60);
    best[0] = 0;
    forbidden = vector<bool>(K, false);
    {
        int id = 0;
        FOR(i,0,N){
            while(positions[id] != x[i][0])++id;
            forbidden[id] = true;
        }
        forbidden[K-1] = true;
    }
    cerr << K << endl;
    FOR(i,0,K){
        if(!forbidden[i])best[i+1] = min(best[i+1], best[i] + positions[i+1]-positions[i]);
        for(int id = i+1; id < K && positions[id] - positions[i] <= D; id++)best[id] = min(best[id], best[i] + T);
    }
    cout << best[K-1] + base_res << endl;
    return 0;
}
