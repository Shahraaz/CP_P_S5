#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

const ll INF = (ll)2e16;
const int N = 100100;
int n;
ll X;
ll ans = 0;
ll a[N];
int p2[N];
int k;

int main()
{
	p2[1] = 1;
	for (int i = 2; i < N; i++)
		p2[i] = p2[i / 2] + 1;

	scanf("%d%lld", &n, &X);
	n--;
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	ll d = X - a[0] + 1;
	a[n] = -INF;
	k = 1;
	while (a[k] == a[k - 1])
		k++;
	while (true)
	{
		//eprintf("k = %d, d = %lld, ans = %lld\n", k, d, ans);
		ll t = a[k - 1] - a[k];
		if (t * (p2[k] - 1) >= d)
		{
			ll z = d / (p2[k] - 1);
			if (d % (p2[k] - 1) == 0)
				z--;
			ans += z * p2[k];
			ans += d - z * (p2[k] - 1);
			break;
		}
		ans += t * p2[k];
		d -= t * (p2[k] - 1);
		k++;
		while (a[k] == a[k - 1])
			k++;
	}
	printf("%lld\n", ans - 1);

	return 0;
}
