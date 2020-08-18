#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int x[1024][2];
int cnt[1024];
int y[2048];
int main(){
    int N,P;
    cin >> N;
    FOR(i,0,N)FOR(j,0,2)cin >> x[i][j];
    cin >>P;
    FOR(i,0,P)cin >> y[i];
    FOR(i,0,N)cnt[i] = 0;
    FOR(i,0,N)FOR(j,0,P)if(y[j] >= x[i][0] && y[j] <= x[i][1])++cnt[i];
    set<int> av;
    FOR(i,0,P)av.insert(y[i]);
    set<int> add;
    FOR(i,0,N-1)if(x[i][1] == x[i+1][0] && av.find(x[i][1]) == av.end() && cnt[i] < 2 && cnt[i+1] < 2){
        add.insert(x[i][1]);
        cnt[i]++;
        cnt[i+1]++;
    }
    FOR(i,0,N)if(cnt[i] > 2){
        cout << "impossible\n";
        return 0;
    }
    FOR(i,0,N){
        int k = x[i][0]+1;
        while(cnt[i] < 2){
            if(av.find(k) != av.end()){
                ++k;
                continue;
            }
            add.insert(k++);
            cnt[i]++;
        }
    }
    cout << add.size() << endl;
    bool first = true;
    for(auto it: add){
        if(first)first = false;
        else cout << " ";
        cout << it;
    }
    cout << endl;
    return 0;
}
