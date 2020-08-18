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

const double pi = acos(-1.0);
const double EPS = 1e-9;

// #include <complex>
// typedef complex<long double> cpx;

struct cpx {
    long double x, y;
    cpx(long double _x = 0.0, long double _y = 0.0) {
        x = _x;
        y = _y;
    }
    cpx operator +(const cpx &other) const {
        return cpx(x + other.x, y + other.y);
    }
    cpx operator -(const cpx &other) const {
        return cpx(x - other.x, y - other.y);
    }
    cpx operator *(const cpx &other) const {
        return cpx(x*other.x-y*other.y, y*other.x+x*other.y);
    }
    cpx operator /(const cpx &other) const {
        long double d = other.x*other.x + other.y*other.y;
        return cpx((x*other.x + y*other.y) / d, -x*other.y + y*other.x);
        // (x + i*y) / (other.x + i*other.y) * (other.x - i*other.y) / (other.x - i*other.y)
    }
};

cpx exp(const cpx &c) {
    long double e = exp(c.x);
    return cpx(cos(c.y) * e, sin(c.y) * e);
}

void fft(cpx *x, int n, bool inv=false) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i < j) swap(x[i], x[j]);
    int m = n>>1;
    while (1 <= m && m <= j) j -= m, m >>= 1;
    j += m; }
  for (int mx = 1; mx < n; mx <<= 1) {
    cpx wp = exp(cpx(0, (inv ? -1 : 1) * pi / mx)), w = 1;
    for (int m = 0; m < mx; m++, w = w * wp) {
      for (int i = m; i < n; i += mx << 1) {
        cpx t = x[i + mx] * w;
        x[i + mx] = x[i] - t;
        x[i] = x[i] + t; } } }
  if (inv) rep(i,0,n) x[i] = x[i] / cpx(n); }

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int l = 2*(n+n)+1;
    while (l&(l-1)) l++;

    cpx *arr = new cpx[l];
    rep(i,0,l) arr[i] = 0;
    rep(i,0,n) {
        long double x;
        cin >> x;
        arr[i] = x * k;
        arr[n+i] = arr[i];
    }

    cpx *prob = new cpx[l];
    rep(i,0,l) prob[i] = 0;
    long double p = 1.0;
    rep(j,0,n-k+1) {
        p /= n-j;
        prob[j] = p;
        p *= n-k-j;
    }

    fft(arr, l);
    fft(prob, l);
    rep(i,0,l) arr[i] = arr[i] * prob[i];
    fft(arr, l, true);

    rep(i,0,n) {
        cout << setprecision(12) << arr[n+i].x  << endl;
    }

    return 0;
}

