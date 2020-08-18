#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int N;
vector<vector<int> > describing_numbers;
vector<tuple<int,int,int> > output;
unordered_map<int,int> mm, re_mm;
vector<bool> marked;
void dfs(int n, int parent){
    marked[n] = true;
    for(auto it: describing_numbers[n]){
        if(marked[it])continue;
        if(n >= N){
            output.push_back(make_tuple(parent+1, it+1, re_mm[n]));
        }
        dfs(it,n);
    }
}

int main(){
    cin >> N;
    describing_numbers.clear();
    set<int> usednums;
    FOR(i,0,N){
        int M;
        cin >> M;
        describing_numbers.push_back(vector<int>(M));
        FOR(j,0,M)cin >> describing_numbers[i][j];
        usednums.insert(all(describing_numbers[i]));
    }
    int K = N;
    re_mm.clear();
    mm.clear();
    for(auto x: usednums){
        mm[x] = K;
        re_mm[K++] = x;
    }
    describing_numbers.resize(K);
    FOR(i,0,N)for(auto &x: describing_numbers[i])x = mm[x];
    FOR(i,0,N)for(auto x: describing_numbers[i])describing_numbers[x].push_back(i);
    output.clear();
    marked = vector<bool>(K,false);
    dfs(0,-1);
    if(((int)output.size()) != N-1){
        cout << "impossible\n";
    } else {
        for(auto it: output){
            int a,b,c;
            tie(a,b,c)=it;
            cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}
