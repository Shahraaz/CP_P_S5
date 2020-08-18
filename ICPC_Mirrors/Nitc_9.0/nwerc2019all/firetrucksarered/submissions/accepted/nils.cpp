#include <bits/stdc++.h>
#include <cstdint>
#include <stdint.h>
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

const int MAXN = 200000;

vector<vi> graph(MAXN, vi());
vector<vi> number(MAXN, vi());
unordered_map<int,int> M;
vector<pii> answer;
bool mark[MAXN] = {0};
int marked = 0;
int n;

void dfs(int i){
    marked++;
    mark[i] = 1;
    rep(c1,0,sz(graph[i])){
        int a = graph[i][c1];
        if(!mark[a]){
            answer.push_back({i,c1});
            dfs(a);
        }
    }
}

int main(){
    cin >> n;
    rep(c1,0,n){
        int mi;
        cin >> mi;
        rep(c2,0,mi){
            int a;
            cin >> a;
            if(M.find(a) == M.end()){
                M[a] = c1;
            }
            else{
                graph[M[a]].push_back(c1);
                number[M[a]].push_back(a);
                graph[c1].push_back(M[a]);
                number[c1].push_back(a);
            }
        }
    }
    dfs(0);
    if(marked != n){
        cout << "impossible\n";
    }
    else{
        rep(c1,0,n-1){
            int a = answer[c1].first;
            int b = answer[c1].second;
            cout << a+1 << " " << graph[a][b]+1 << " " << number[a][b] << "\n";
         }
    }
    return 0;
}

