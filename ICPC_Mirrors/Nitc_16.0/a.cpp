#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(), a.end()) - a.begin());
const ll mod = 1e9 + 7;

const int N = 5e4 + 1;
long double a[N], b[N];
ll n;

long double calc(long double m)
{
    long double dist = 0;
    for (ll i = 0; i < n; i++)
    {
        long double t = sqrt((a[i] - m) * (a[i] - m) + b[i] * b[i]);
        if (dist < t)
            dist = t;
    }
    return dist;
}

int main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll T = clock();

    // cout << fixed << setprecision(7);
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        long double l = -200000, r = 200000;
        for (ll i = 0; i < n; i++)
        {
            // cin >> a[i] >> b[i];
            scanf("%LF %LF",&a[i],&b[i]);
        }
        long double eps = 1e-6;
        for (int i = 0; i < 80; i++)
        {
            long double m1 = l + (r - l) / 3;
            long double m2 = r - (r - l) / 3;
            long double f1 = calc(m1);
            long double f2 = calc(m2);
            if (f1 > f2)
                l = m1;
            else
                r = m2;
        }
        // cout<<l<<" "<<calc(l)<<"\n";
        printf("%7LF %7LF\n", l, calc(l));
    }

    // cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    // T = clock();
    return 0;
}