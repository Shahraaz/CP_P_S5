#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int D;
vector<ll> v;
vector<pair<ll,int> > ids;
vector<vector<int> > dp[2];

void update(int id, int pn){
    dp[pn][0][id] = 1;
    FOR(d,1,D){
        int m = id >> d;
        FOR(x,0,2){
            int l1 = dp[x][d-1][m*2];
            int l = l1 + dp[x^(l1&1)][d-1][m*2+1];
            dp[x][d][m] = l;
        }
    }
}

int main(){
    int N;
    ll fake, chatuser;
    cin >> N >> fake >> chatuser;
    v = vector<ll>(N);
    ids = vector<pair<ll,int> > (N);
    FOR(i,0,N)cin >> v[i];
    FOR(i,0,N)ids[i] = make_pair(abs(v[i]) + 1, i);
    D = 0;
    while((1<<D) <= N*2){
        FOR(i,0,2)dp[i].push_back(vector<int>((N >> D)+4,0));
        ++D;
    }
    FOR(i,0,N){
        if(v[i] > 0)update(i,1);
        if(v[i] < 0)update(i,0);
    }
    ll res = (N - max(dp[0][D-1][0], dp[1][D-1][0])) * chatuser;
    sort(all(ids));
    for(auto it: ids){
        int i = it.second;
        if(v[i] <= 0)update(i,1);
        if(v[i] >= 0)update(i,0);
        res = min(res, (N - max(dp[0][D-1][0], dp[1][D-1][0])) * chatuser + it.first * fake);
    }
    cout << res << endl;
    return 0;
}
