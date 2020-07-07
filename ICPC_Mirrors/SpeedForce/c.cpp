#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pop_b pop_back
#define pf push_front
#define pop_f pop_front

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;
typedef vector<int> vi;

#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
    }
void err(istream_iterator<string> it)
{
}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
#define LB(x, v) (lower_bound(x.begin(), x.end(), v) - x.begin())
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep2(i, l, r) for (ll i = (l); i < (r); i++)
#define rep2r(i, l, r) for (ll i = (r)-1; i >= (l); i--)

int main()
{
    int n;
    cin >> n;
    ll a[n];
    map<ll, int> m;
    vi v;
    rep(i, n)
            cin >>
        a[i],
        m[a[i]]++;
    for (auto it : m)
        v.pb(it.se);
    sort(v.begin(), v.end());
    int p = v.size();
    v.pb(INT_MAX);
    int ans = 0;
    rep2(i, 1, 200005)
    {
        int x = i, val = 0, ptr = -1;
        rep(j, v.size())
        {
            int ptr2 = lower_bound(v.begin() + (ptr == -1 ? 0 : ptr + 1), v.end(), x) - v.begin();
            /*
             1 10* 10** 10 10
             1
             2
             4             
            */
            if (ptr == ptr2)
                ptr2++;
            if (ptr2 < p and ptr < ptr2)
            {
                val += x;
                // error(val);
                ans = max(ans, val);
                ptr = ptr2;
                x *= 2;
            }
            else
            {
                break;
            }
        }
        // cout<<endl;
    }
    cout << ans << endl;
}