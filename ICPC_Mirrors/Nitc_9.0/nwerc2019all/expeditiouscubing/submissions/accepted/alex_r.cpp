#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main(){
    vector<long double> vd(5);
    FOR(i,0,5)cin >> vd[i];
    vector<int> v(5);
    FOR(i,0,5)v[i] = (vd[i]*100 + 0.5);
    int target = v[4];
    v.pop_back();
    sort(v.begin(), v.end());
    if(v[1]+v[2]+v[3]<=target*3)cout << "infinite\n";
    else if(v[0]+v[1]+v[2] > target*3)cout << "impossible\n";
    else printf("%.2lf\n", 0.01*(target*3-v[1]-v[2]));
    return 0;
}
