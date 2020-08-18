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

struct union_find {
  vi p; union_find(int n) : p(n, -1) { }
  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }
  bool unite(int x, int y) {
    int xp = find(x), yp = find(y);
    if (xp == yp) return false;
    if (p[xp] > p[yp]) swap(xp,yp);
    p[xp] += p[yp], p[yp] = xp;
    return true; }
  int size(int x) { return -p[find(x)]; } };

int main() {
    int n;
    cin >> n;

    vector<vi> nums(n);
    rep(i,0,n) {
        int c;
        cin >> c;
        rep(j,0,c) {
            int x;
            cin >> x;
            nums[i].push_back(x);
        }
        sort(nums[i].begin(), nums[i].end());
    }

    union_find uf(n);
    vector<tuple<int,int,int> > es;
    rep(i,0,n) {
        rep(j,i+1,n) {
            if (uf.find(i) != uf.find(j)) {
                bool found = false;
                int common = -1;
                if (nums[i].size() < nums[j].size()) {
                    iter(it,nums[i]) {
                        if (binary_search(nums[j].begin(), nums[j].end(), *it)) {
                            found = true;
                            common = *it;
                            break;
                        }
                    }
                } else {
                    iter(it,nums[j]) {
                        if (binary_search(nums[i].begin(), nums[i].end(), *it)) {
                            found = true;
                            common = *it;
                            break;
                        }
                    }
                }

                if (found) {
                    es.push_back({ i, j, common });
                    uf.unite(i,j);
                }
            }
        }
    }

    if (uf.size(0) != n) {
        cout << "impossible" << endl;
        return 0;
    }

    for (auto [a,b,c] : es) {
        cout << a+1 << " " << b+1 << " " << c << endl;
    }

    return 0;
}

