//Optimise
#include <bits/stdc++.h>
using namespace std;

// #define multitest 1
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
	std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
	const char *comma = strchr(names + 1, ',');
	std::cerr.write(names, comma - names) << " = " << arg1;
	ZZ(comma, args...);
}
#else
#define db(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;

void solve()
{
	int n;
	cin >> n;
	vector<int> A(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> A[i];
	auto B = A;
	vector<int> ans;
	for (int i = n; i > 0; --i)
	{
		if (A[i])
		{
			ans.pb(i);
			int j = i;
			db(j);
			for (int k = 1; k * k <= j; ++k)
			{
				if (j % k == 0)
				{
					if (k == j / k)
					{
						db(k);
						A[k] = (A[k] + 1) % 2;
					}
					else
					{
						db(k, j / k);
						A[k] = (A[k] + 1) % 2;
						A[j / k] = (A[j / k] + 1) % 2;
					}
				}
			}
		}
	}
	vector<int> C = ans;
	// cout << ans.size() << '\n';
	for (int i = 1; i <= n; ++i)
		if (A[i])
		{
			db(i);
			cout << -1;
			return;
		}
	cout << C.size() << '\n';
	for (int x : C)
		cout << x << ' ';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
#ifdef multitest
	cin >> t;
#endif
	while (t--)
		solve();
#ifdef TIME
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}