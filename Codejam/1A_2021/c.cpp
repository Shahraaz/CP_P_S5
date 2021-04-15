#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif

#define all(v) v.begin(), v.end()
#define pb push_back
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;

std::ostream &
operator<<(std::ostream &dest, __int128_t value)
{
    std::ostream::sentry s(dest);
    if (s)
    {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do
        {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0)
        {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len)
        {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

const int LIM = 125;
__int128_t C[LIM][LIM];

void solveCase()
{
    int n, m;
    cin >> n >> m;
    vector<string> x(n);
    vector<int> wyn(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> wyn[i];
    int lim = 1 << (n - 1);
    vector<long long> ile(lim), ak(lim);
    vector<__int128_t> res(lim);
    vector<int> typ(m);
    for (int j = 0; j < m; ++j)
    {
        int mb = 0;
        for (int i = 1; i < n; ++i)
            mb += (x[0][j] == x[i][j]) ? 0 : (1 << (i - 1));
        typ[j] = mb;
        ile[mb]++;
    }
    db(typ);
    db(ile);
    __int128_t All = 0;
    function<void(int, __int128_t)> bt = [&](int mb, __int128_t spo) -> void {
        if (mb == lim)
        {
            for (int i = 0; i < n; ++i)
                if (wyn[i] != 0)
                    return;
            db(spo, ak);
            All += spo;
            for (int i = 0; i < lim; ++i)
                res[i] += ak[i] * spo;
            return;
        }
        for (int j = 0; j <= ile[mb] + 1; ++j)
        {
            wyn[0] -= j;
            for (int i = 1; i < n; ++i)
            {
                if (mb & (1 << (i - 1)))
                    wyn[i] -= ile[mb] - j;
                else
                    wyn[i] -= j;
            }
            ak[mb] = j;
            bt(mb + 1, spo * C[ile[mb]][j]);

            wyn[0] += j;
            for (int i = 1; i < n; ++i)
            {
                if (mb & (1 << (i - 1)))
                    wyn[i] += ile[mb] - j;
                else
                    wyn[i] += j;
            }
        }
    };
    bt(0, 1);
    __int128_t ok = 0;
    for (int i = 0; i < lim; ++i)
        ok += max(res[i], All * ile[i] - res[i]);
    db(ok, All);
    string out;
    for (int i = 0; i < m; ++i)
    {
        if (res[typ[i]] >= All * ile[typ[i]] - res[typ[i]])
            out += x[0][i];
        else
            out += x[0][i] ^ 'T' ^ 'F';
    }
    db(out);
    auto g = __gcd(All, ok);
    All /= g;
    ok /= g;
    cout << out << ' ' << ok << '/' << All << '\n';
}

int32_t main()
{
    for (int i = 0; i < LIM; ++i)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase();
    }
    return 0;
}