//Optimise
#include <bits/stdc++.h>
using namespace std;

#define multitest 1
#ifdef WIN32
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
	out << '[' << p.first << ", " << p.second << ']';
	return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
	std::cerr << name << " { ";
	for (const auto &v : arg)
		cerr << v << ' ';
	cerr << " }\n";
}
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
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;
auto TimeStart = chrono::steady_clock::now();

const int nax = 2e5 + 10;

int cnt = 0;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if ((ll)a.f * b.s == (ll)b.f * a.s)
		return a.f > b.f;
	return ((ll)a.f * b.s) > ((ll)b.f * a.s);
}

void solve()
{
	++cnt;
	int u, v, d, ss;
	cin >> d >> ss;
	vector<pair<int, int>> Slot;
	int OnlyEat = 0, OnlyCode = 0;
	for (int i = 0; i < ss; ++i)
	{
		cin >> u >> v;
		if (u == 0)
			OnlyEat += v;
		else if (v == 0)
			OnlyCode += u;
		else
		{
			Slot.pb(make_pair(u, v));
		}
	}
	sort(Slot.begin(), Slot.end(), cmp);
	pc(Slot);
	ss = Slot.size();
	vector<ll> EatSum(ss + 1), CodeSum(ss + 1);
	for (int i = 1; i <= ss; ++i)
		CodeSum[i] += Slot[i - 1].f + CodeSum[i - 1];
	for (int i = ss - 1; i >= 0; --i)
		EatSum[i] += Slot[i].s + (i < (ss - 1) ? EatSum[i + 1] : 0);
	string res;
	int code, eat;
	for (int i = 0; i < d; ++i)
	{
		cin >> code >> eat;
		code = max(0, code - OnlyCode);
		eat = max(0, eat - OnlyEat);
		db(EatSum[0], eat, CodeSum[ss], code);
		if (EatSum[0] < eat || CodeSum[ss] < code)
		{
			db("Here");
			res += "N";
		}
		else
		{
			int start = 0, end = ss, appr = -1;
			int itr = 300;
			while (start <= end && itr--)
			{
				int mid = (start + end) / 2;
				long long code1 = CodeSum[mid];
				db(mid, code1, code);
				if (code1 >= code)
				{
					appr = mid;
					end = mid - 1;
				}
				else
					start = mid + 1;
			}
			long long code1 = CodeSum[appr], eat1 = EatSum[appr];
			db(appr, code1, eat1, code, eat);
			if (code1 >= code && eat1 >= eat)
				res += "Y";
			else
			{
				long long prevCode, prevEat;
				{
					using ld = long double;
					prevEat = Slot[appr - 1].s;
					prevCode = Slot[appr - 1].f;
					db(Slot[appr - 1], appr - 1);
					long long exCessCOde = code1 - code;
					ld rat = (ld)exCessCOde / prevCode;
					ld excessEat = rat * prevEat;
					excessEat += eat1;
					db(excessEat, eat, rat, prevCode);
					if (excessEat >= eat)
						res += "Y";
					else
					{
						db("here3");
						res += "N";
					}
				}
			}
		}
	}
	std::cout << "Case #" << cnt << ": " << res << '\n';
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
#ifdef WIN32
	cerr << "\n\nTime elapsed: " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " seconds.\n";
#endif
	return 0;
}