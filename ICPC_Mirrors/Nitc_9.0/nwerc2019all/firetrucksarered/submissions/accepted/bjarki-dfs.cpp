#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int main() {
    int n;
    cin >> n;

    vector<vi> adjl(n);
    vector<bool> visl(n);

    map<int,vi> adjr;
    set<int> visr;

    rep(i,0,n) {
        int c;
        cin >> c;
        rep(j,0,c) {
            int x;
            cin >> x;
            adjl[i].push_back(x);
            adjr[x].push_back(i);
        }
    }

    vector<tuple<int,int,int> > es;
    stack<int> S;
    S.push(0);
    visl[0] = true;
    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        iter(it,adjl[cur]) {
            if (visr.find(*it) == visr.end()) {
                visr.insert(*it);

                iter(jt,adjr[*it]) {
                    if (!visl[*jt]) {
                        visl[*jt] = true;
                        es.push_back({ cur, *jt, *it });
                        S.push(*jt);
                    }
                }
            }
        }
    }

    rep(i,0,n) {
        if (!visl[i]) {
            cout << "impossible" << endl;
            return 0;
        }
    }

    for (auto [a,b,c] : es) {
        cout << a+1 << " " << b+1 << " " << c << endl;
    }

    return 0;
}

