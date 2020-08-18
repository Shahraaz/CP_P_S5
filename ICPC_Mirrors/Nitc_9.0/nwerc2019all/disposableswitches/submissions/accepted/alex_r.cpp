#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

const int MAXN = 2048;
const int MAXM = 10100;
int N,M;
int ed[MAXM][3];
vi adj[MAXN];
ll dp[MAXN][MAXN];
int marked[MAXN];
void mark_nodes(int D){
    queue<pair<int,int> > q;
    q.push(make_pair(N,D));
    marked[N] = D;
    while(!q.empty()){
        auto c = q.front();
        int n = c.first;
        int d = c.second;
        q.pop();
        if(d == 0)continue;
        for(auto eid: adj[n]){
            int to = n ^ ed[eid][0] ^ ed[eid][1];
            if(dp[d-1][to]+ed[eid][2] == dp[d][n]){
                if(marked[to] != D){
                    marked[to] = D;
                    q.push(make_pair(to,d-1));
                }
            }
        }
    }
}
pair<ll,ll> getcut(pair<ll,int> v1, pair<ll,int> v2){
    ll d1 = v1.first - v2.first;
    ll d2 = v1.second - v2.second;
    return make_pair(abs(d1), abs(d2));
}
int countbits(ll v){
    if(v == 0)return 1;
    return 1 + countbits(v >> 1);
}
int main(){
    memset(marked,0,sizeof(marked));
    cin >> N >> M;
    FOR(i,0,M)FOR(j,0,3)cin >> ed[i][j];
    FOR(i,0,N+1)adj[i].clear();
    FOR(i,0,M)FOR(j,0,2)adj[ed[i][j]].push_back(i);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    ll oo = dp[0][0];
    dp[0][1] = 0;
    FOR(i,0,N){FOR(m,0,M){
        FOR(k,0,2)if(dp[i+1][ed[m][k]] > dp[i][ed[m][k^1]] + ed[m][2]){
            dp[i+1][ed[m][k]] = dp[i][ed[m][k^1]] + ed[m][2];
        }
    }
    }
    vector<pair<ll,int> > best;
    vector<pair<ll,int> > latest;
    FOR(i,1,N){
        if(dp[i][N] == oo)continue;
        if(!best.empty() && best[best.size()-1].first < dp[i][N])continue;
        if(!best.empty() && best[best.size()-1].first == dp[i][N])latest.push_back(make_pair(dp[i][N],i));
        else {
            while(best.size() > 1){
                auto cut1 = getcut(best[best.size()-1], best[best.size()-2]);
                auto cut2 = getcut(make_pair(dp[i][N], i), best[best.size()-1]);
                int b1 = countbits(cut1.first) + countbits(cut2.second);
                int b2 = countbits(cut2.first) + countbits(cut1.second);
                if(b1 >= 63 || b2 >= 63){
                    cerr << b1 << " " << b2 << endl;
                }
                assert(b1 < 63);
                assert(b2 < 63);
                if(cut1.first *cut2.second < cut1.second * cut2.first){
                    best.pop_back();
                } else {
                    break;
                }
            }
            best.push_back(make_pair(dp[i][N],i));
            latest.clear();
        }
    }
    for(auto it: latest)best.push_back(it);
    for(auto it: best)mark_nodes(it.second);
    int num = 0;
    FOR(i,1,N+1)if(0 == marked[i])++num;
    cout << num << endl;
    bool first = true;
    FOR(i,1,N+1)if(0 == marked[i]){
        if(first)first = false;
        else cout << " ";
        cout << i;
    }
    cout << endl;
    return 0;
}
