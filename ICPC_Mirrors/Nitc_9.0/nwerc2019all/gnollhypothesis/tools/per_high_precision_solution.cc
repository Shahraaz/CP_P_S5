#include <bits/stdc++.h>
#include <mpreal.h>
using namespace std;

const int PRECISION = 500; // in bits
const int OUTPUT_DIGITS = 12; // absolute precision, in decimal digits

typedef mpfr::mpreal Real;
#define ln mpfr::log
#define exp mpfr::exp
typedef complex<Real> Complex;

vector<Complex> fft(const vector<Complex> x, bool inverse=false) {
    const Real pi = mpfr::const_pi();
    int n = x.size();
    vector<Complex> xt(n);
    for (int i = 0; i < n; ++i) {
        int ri = 0;
        for (int M = 1; M < n; M <<= 1) ri = 2*ri + !!(i & M);
        xt[i] = x[ri];
    }
    for (int M = 1; M < n; M <<= 1) {
        auto w = polar((Real)1.0, (1-2*inverse)*pi/M);
        for (int offs = 0; offs < n; offs += 2*M) {
            complex<Real> wp(1.0);
            for (int step = 0; step < M; ++step) {
                auto u = xt[offs+step];
                auto t = xt[offs+step+M] * wp;
                wp *= w;
                xt[offs+step] = u + t;
                xt[offs+step+M] = u - t;
            }
        }
    }
    if (inverse)
        for (auto &res: xt) res /= n;
    return xt;
}

string format(Real x) { // well this is ugly
    ostringstream o;
    o.precision(cout.precision());
    o << fixed << x;
    string ret = o.str();
    while (ret.back() == '0') ret.pop_back();
    if (ret.back() == '.') ret.pop_back();
    if (ret == "-0") ret = "0";
    return ret;
}

int main(void) {
    mpfr::mpreal::set_default_prec(PRECISION);
    int n, k;
    cin >> n >> k;
    vector<Real> log_fac(n+1);

    int w = 1;
    while ((1<<w) < 2*n) ++w;
    
    for (int i = 2; i <= n; ++i)
        log_fac[i] = log_fac[i-1] + ln(i);

    vector<Complex> f(1<<w), bp(1<<w);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        f[i-n+(1<<w)] = f[i];
    }

    for (int j = 0; j < n-k+1; ++j) {
        // bp[j] = {n-j-1 choose k-1} / {n choose k}
        bp[j] = exp((log_fac[n-j-1] - log_fac[k-1] - log_fac[n-j-k]) -
                    (log_fac[n] - log_fac[k] - log_fac[n-k]));
    }

    auto ft = fft(f), bt = fft(bp);
    vector<Complex> gt(1<<w);
    for (int i = 0; i < 1<<w; ++i)
        gt[i] = ft[i] * bt[i];
    auto g = fft(gt, true);

    cout.precision(OUTPUT_DIGITS);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << format(real(g[i]));
    }
    cout << endl;
}
