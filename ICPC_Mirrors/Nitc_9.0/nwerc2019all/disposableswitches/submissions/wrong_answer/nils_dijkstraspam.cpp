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

bool mark[MAXN] = {0};
ll dist[MAXN][MAXN] = {0};

void dijkstra(ll c, int from){
    rep(c1,0,n){
        mark[c1] = 0;
        dist[from][c1] = 1e15;
    }
    dist[from][from] = 0;
    priority_queue<pll> pq;
    pq.push({0, from});
    while(!pq.empty()){
        int i = pq.top().second;
        pq.pop();
        if(!mark[i]){
            mark[i] = 1;
            rep(c1,0,sz(graph[i])){
                int j = graph[i][c1];
                if(dist[from][j] > dist[from][i] + weights[i][c1] + c){
                    dist[from][j] = dist[from][i] + weights[i][c1] + c;
                    pq.push({-dist[from][j],j});
                }
            }
        }
    }
}

void spam(ll c){
    dijkstra(c,0);
    dijkstra(c,n-1);
    rep(c1,0,n){
        if(dist[0][c1] + dist[n-1][c1] == dist[0][n-1])bad[c1] = 1;
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

    ll R = maxw*ll(n);
    ll lim = 1000;
    spam(0);
    rep(c1,0,lim){
        spam(random(R/100+1));
    }
    rep(c1,0,lim){
        spam(random(R/10+1));
    }
    rep(c1,0,lim){
        spam(random(R+1));
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

