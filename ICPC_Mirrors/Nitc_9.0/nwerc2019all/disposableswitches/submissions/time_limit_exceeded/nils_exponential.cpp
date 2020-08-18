#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const int MAXN = 2001;

vector<vi> graph(MAXN, vi());
vector<vi> weights(MAXN, vi());

bool bad[MAXN] = {0};
const ll inf = 1e14+1;
ll DP[MAXN][MAXN] = {0};

bool visited[MAXN][MAXN] = {0};

pll treat(pll r){
    if(r.second < 0)return {-r.first, -r.second};
    return r;
}

bool geq(pll rat1, pll rat2){
    rat1 = treat(rat1); rat2 = treat(rat2);
    return rat1.first * rat2.second >= rat2.first * rat1.second;
}

// Check if shortest path with e edges is on the lower hull.
bool check_edgecount(ll e){
    pll ma = {0,1};
    pll mi = {1e14,1};
    for(ll e2 = 1; e2 < n; e2++){
        if(e2 == e)continue;
        if(DP[0][e2] >= inf)continue;
        pll r = {DP[0][e2] - DP[0][e], e - e2};
        if(e2 > e){
            if(geq(r,ma)){
                ma.first = r.first;
                ma.second = r.second;
            }
        }
        if(e2 < e){
            if(geq(mi,r)){
                mi.first = r.first;
                mi.second = r.second;
            }
        }
    }

    return geq(mi,ma);
}

// Does a DFS through the DP-states and marks vertices.
void mark_states(int i, int e){
   // if(visited[i][e])return;
    visited[i][e] = 1;
    bad[i] = 1;
    rep(c1,0,sz(graph[i])){
        int a = graph[i][c1];
        if(DP[a][e-1] + weights[i][c1] == DP[i][e]){
            mark_states(a,e-1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll maxw = 0;
    rep(c1,0,m){
        int a,b;
        ll w;
        cin >> a >> b >> w;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        weights[a].push_back(w);
        weights[b].push_back(w);
        maxw = max(maxw, w);
    }

    // DP to find shortest path of different edge-counts.
    rep(e,0,n){
        rep(i,0,n){
            DP[i][e] = inf;
            if(e == 0){
                DP[i][e] = inf * ll(i != n-1);
            }
            else{
                rep(c1,0,sz(graph[i])){
                    DP[i][e] = min(DP[i][e], weights[i][c1] + DP[graph[i][c1]][e-1]);
                }
            }
        }
    }

    rep(e,1,n){
        if(check_edgecount(e))mark_states(0,e);
    }

    vi answer;
    rep(c1,0,n){
        if(!bad[c1])answer.push_back(c1);
    }
    cout << sz(answer) << "\n";
    rep(c1,0,sz(answer)){
        cout << answer[c1]+1 << " ";
    }cout << "\n";

    return 0;
}

