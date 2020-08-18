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

vii land;
int pos[210][210];
double dist[210][210];

int main() {
    int s, l, k, n;
    cin >> s >> l >> k >> n;
    int c = 0;
    rep(i,0,n) {
        int a, b;
        cin >> a >> b;
        land.push_back(ii(c,a));
        c = b;
    }
    land.push_back(ii(c,s));
    sort(land.begin(), land.end());
    n++;

    memset(pos,-1,sizeof(pos));
    rep(i,0,n) {
        pos[i][i] = land[i].first;
        int nxt = pos[i][i] + k;
        rep(j,i+1,n) {
            if (land[j].first <= nxt && nxt <= land[j].second) {
                pos[i][j] = nxt;
                nxt += k;
            }
        }
    }

    rep(i,0,n) rep(j,0,n) dist[i][j] = INFINITY;

    double mn = INFINITY;
    priority_queue<pair<double,ii>, vector<pair<double,ii> >, greater<pair<double,ii> > > pq;
    dist[0][0] = 0.0;
    pq.push(make_pair(0.0, ii(0,0)));

    while (!pq.empty()) {
        pair<double, ii> cur = pq.top();
        pq.pop();

        int at = pos[cur.second.first][cur.second.second],
            p = cur.second.second;

        if (cur.first != dist[cur.second.first][cur.second.second]) {
            continue;
        }

        if (land[n-1].second - at <= l) {
            mn = min(mn, cur.first + k);
        }

        if (p == n-1) {
            mn = min(mn, cur.first + (land[n-1].second - at));
        }

        rep(q,p+1,n) {
            if (land[p].second + l < land[q].first) break;

            // Jump as far as we can
            if (land[q].first <= at + l && at + l <= land[q].second) {
                assert(pos[p][q] == at + l);
                double ndist = cur.first + k;
                if (ndist < dist[p][q]) {
                    dist[p][q] = ndist;
                    pq.push(make_pair(ndist, ii(p,q)));
                }
            }

            double ndist = INFINITY;
            if (at + l >= land[q].first) { // We only need one jump
                ndist = min(ndist, cur.first + k);
            } else { // One jump won't make it

                // Ride far, and then make one jump landing on land[q].first
                ndist = min(ndist, cur.first + ((land[q].first - l) - at + k));

                // Ride a little bit, and then make jumps until we on land[q].first
                int t = (land[q].first - at) / l;
                ndist = min(ndist, cur.first + ((land[q].first - t*l) - at + t*k));

                // Make jumps until we on land[q].first
                if ((land[q].first - at) % l != 0) {
                    ndist = min(ndist, cur.first + ((t+1)*k));
                }
            }

            if (ndist < dist[q][q]) {
                dist[q][q] = ndist;
                pq.push(make_pair(ndist, ii(q,q)));
            }
        }
    }

    cout << setprecision(12) << mn << endl;

    return 0;
}

