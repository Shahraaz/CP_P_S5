//Optimise
#include <bits/stdc++.h>
using namespace std;

#define Debug
#ifdef Debug
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
#define all(v) v.begin(), v.end()

const int nax = 6 * (11) + 10;

// vector<vector<vector<int>>> isPossible(nax, vector<vector<int>>(nax *(nax + 1) / 2, vector<int>(nax *(nax + 1) / 2, -1)));

class EpicPartition
{
	int n;
	// int solve(int pos, int sum1, int sum2)
	// {
	// 	if (pos == n)
	// 		return sum1 == 0 && sum2 == 0;
	// 	if (sum1 < 0 || sum2 < 0)
	// 		return false;
	// 	auto &ret = isPossible[pos][sum1][sum2];
	// 	if (ret >= 0)
	// 		return ret;
	// 	ret = solve(pos + 1, sum1, sum2);
	// 	if (!ret)
	// 		ret = solve(pos + 1, sum1 - pos - 1, sum2);
	// 	if (!ret)
	// 		ret = solve(pos + 1, sum1, sum2 - pos - 1);
	// 	return ret;
	// }

public:
	string createPartition(ll N)
	{
		N = 6 * N;
		n = N;
		ll total = N * (N + 1) / 2;
		if (total % 4 == 0)
		{
			db(N);
			string str;
			str.resize(N + 1, '.');
			vector<int> A, B, C;
			A = {1, 2, 3, 4, 6, 18, 19, 22};
			B = {5, 7, 8, 9, 10, 11, 12, 13};
			C = {14, 15, 16, 17, 20, 21, 23, 24};
			for (auto &pos : A)
				str[pos] = 'a';
			for (auto &pos : B)
				str[pos] = 'b';
			for (auto &pos : C)
				str[pos] = 'c';
			for (size_t i = 25; i <= N; i++)
				str[i] = str[i - 24];
			reverse(all(str));
			str.pop_back();
			reverse(all(str));
			return str;
		}
		return "";
	}
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
	EpicPartition e;
	for (size_t i = 1; i <= 20; i++)
		cout << i << ' ' << e.createPartition(i) << '\n';
	return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!