#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

int main(){
    int N, K;
    cin >> N >> K;
    vector<long double> p(N), pn(N), res(N);
    FOR(i,0,N)cin >> p[i];
    pn[0] = K/(long double)N;
    FOR(i,1,N)pn[i] = pn[i-1]*(1-(K-1)/(long double)(N-i)); // pn[i] = probability that current monster is active and at least i previous monsters are not active
    FOR(i,0,N)FOR(j,0,N)res[i] += pn[j] * p[(i-j+N) % N];
    FOR(i,0,N)printf("%.9lf%c", (double)res[i], ((i==N-1)?'\n':' '));
    return 0;
}
