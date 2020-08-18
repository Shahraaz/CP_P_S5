// XXX: As Donald Knuth said: "Beware of bugs in the above code; I have only proved it correct, not tried it."
// XXX: This solution currently assumes that intervals are disjoint.
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
const ll DINF = 1000000000000000000LL;

vii water;
ll pos[210][210],
   poscnt[210][210];
ll dist[210][210];

int main() {
    ll s, l, k, n;
    cin >> s >> l >> k >> n;
    ll c = 0;
    rep(i,0,n) {
        ll a, b;
        cin >> a >> b;
        water.push_back(ii(c,a));
        c = b;
    }
    water.push_back(ii(c,s));
    sort(water.begin(), water.end());
    n++;

    // rep(i,0,n) {
    //     cout << i << ": " << water[i].first << " " << water[i].second << endl;
    // }

    memset(pos,-1,sizeof(pos));
    rep(i,0,n) {
        pos[i][i] = water[i].first;
        poscnt[i][i] = 0;
        ll cnt = (water[i].second - pos[i][i]) / l + 1;
        ll nxt = pos[i][i] + cnt * l;
        rep(j,i+1,n) {
            if (nxt >= water[j].first) {
                pos[i][j] = min(nxt, (ll)water[j].second);
                poscnt[i][j] = cnt;
            }
            if (j+1 < n && nxt < water[j+1].first) {
                ll add = (water[j].second - pos[i][j]) / l + 1;
                cnt += add;
                nxt = pos[i][j] + add * l;
            }
        }
    }

    rep(i,0,n) rep(j,0,n) dist[i][j] = DINF;

    ll mn = DINF;
    priority_queue<pair<ll,ii>, vector<pair<ll,ii> >, greater<pair<ll,ii> > > pq;
    dist[0][0] = 0;
    pq.push(make_pair(0, ii(0,0)));

    while (!pq.empty()) {
        pair<ll, ii> cur = pq.top();
        pq.pop();

        ll at = pos[cur.second.first][cur.second.second],
           p = cur.second.second;

        if (cur.first != dist[cur.second.first][cur.second.second]) {
            continue;
        }

        if (water[n-1].second - at <= l) {
            mn = min(mn, cur.first + k);
        }

        if (p == n-1) {
            ll left = water[n-1].second - at;
            mn = min(mn, cur.first + left);
            mn = min(mn, cur.first + (left + l - 1) / l * k);
            mn = min(mn, cur.first + left / l * k + left % l);
        }

        rep(q,p+1,n) {
            if (water[p].second + l < water[q].first) break;

            // Jump as far as we can
            if (pos[cur.second.first][q] != -1) {
                ll ndist = cur.first + (poscnt[cur.second.first][q] - poscnt[cur.second.first][cur.second.second]) * k;
                if (ndist < dist[cur.second.first][q]) {
                    dist[cur.second.first][q] = ndist;
                    pq.push(make_pair(ndist, ii(cur.second.first,q)));
                }
            }

            ll ndist = DINF;
            if (at + l >= water[q].first) { // We only need one jump
                ndist = min(ndist, cur.first + k);
            } else { // One jump won't make it

                // Ride far, and then make one jump landing on water[q].first
                ndist = min(ndist, cur.first + ((water[q].first - l) - at + k));

                // Ride a little bit, and then make jumps until we on water[q].first
                ll t = (water[q].first - at) / l;
                ndist = min(ndist, cur.first + ((water[q].first - t*l) - at + t*k));

                // Make jumps until we on water[q].first
                if ((water[q].first - at) % l != 0) {
                    ndist = min(ndist, cur.first + ((t+1)*k));
                }
            }

            if (ndist < dist[q][q]) {
                dist[q][q] = ndist;
                pq.push(make_pair(ndist, ii(q,q)));
            }
        }
    }

    cout << mn << endl;

    return 0;
}

