#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)

vector<ll> h;
int M,N,K;
double calc(){
    double res = 0;
    map<ll,int> mem;
    ll c = 0;
    mem[0] = 0;
    ll lo = 0;
    FOR(i,0,N){
        c += h[i] - M;
        if(c < lo){
            mem[-c] = i+1;
            lo = c;
        } else {
            auto x = mem.lower_bound(-c);
            assert(x != mem.end());
            auto position = x->second;
            auto value = x->first;
            if(position == 0){
                res = max(res, (double)i+1);
            } else {
                ll s = h[position-1]-M;
                assert(s < 0);
                ll dif = -value - c;
                double rel = dif / (double) s;
                assert(dif <= 0);
                assert(rel < 1);
                res = max(res, rel + (i+1-position));
            }
        }
    }
    return res;
}

int main(){
    cin >> N >> K;
    ll Y;
    cin >> Y;
    h=vector<ll>(N);
    FOR(i,0,N){
        ll YY;
        cin >> YY;
        h[i] = YY-Y;
        Y = YY;
    }
    FOR(k,0,K){
        double mm;
        cin >> mm;
        M = (mm*10)+0.5;
        double res = calc();
        reverse(all(h));
        res = max(res, calc());
        if(res < 0.5) {
            cout << "impossible\n";
        } else {
            printf("%.9lf\n", res);
        }
    }
    return 0;
}
