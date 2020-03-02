// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
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
    while (*name == ',' || *name == ' ')
        name++;
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1, typename... Args>
void PC(const char *names, Arg1 &&arg1, Args &&... args)
{
    while (*names == ',' || *names == ' ')
        names++;
    const char *comma = strchr(names, ',');
    std::cerr.write(names, comma - names) << " { ";
    for (const auto &v : arg1)
        cerr << v << ' ';
    cerr << " }\n";
    PC(comma, args...);
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
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 1e6 + 5, MOD = 1000000007;

map<vector<int>, int> mapp[26][26];
set<int> lengths;
int freq[NAX][26];
ll x[NAX];
string s;

class Solution
{
private:
    void reset()
    {
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                mapp[i][j].clear();
        memset(freq, 0, sizeof freq);
        lengths.clear();
    }

public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        reset();
        int L;
        cin >> L;
        // db(L);
        for (int i = 0; i < L; i++)
        {
            string str;
            cin >> str;
            db(str);
            vector<int> Freq(26);
            for (auto &c : str)
                Freq[c - 'a']++;
            mapp[str[0] - 'a'][str.back() - 'a'][Freq]++;
            lengths.insert((int)str.size());
        }
        // pc(lengths);
        string c1, c2;
        int n, a, b, c, d;
        cin >> c1 >> c2;
        cin >> n >> a >> b >> c >> d;
        x[0] = c1[0];
        x[1] = c2[0];
        string s;
        s += c1;
        s += c2;
        for (int i = 2; i < n; i++)
        {
            x[i] = (a * x[i - 1] + b * x[i - 2] + c) % d;
            s += char(97 + (x[i] % 26));
        }
        db(s);
        freq[0][s[0] - 'a']++;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
                freq[i][j] = freq[i - 1][j];
            freq[i][s[i] - 'a']++;
        }
        vector<int> v(26);
        int ans = 0;
        for (auto &len : lengths)
        {
            for (int i = 0; i + len <= n; i++)
            {
                int j = i + len - 1;
                for (int k = 0; k < 26; k++)
                {
                    v[k] = freq[j][k];
                    if (i > 0)
                        v[k] -= freq[i - 1][k];
                }
                if (mapp[s[i] - 'a'][s[j] - 'a'].find(v) != mapp[s[i] - 'a'][s[j] - 'a'].end())
                {
                    ans += mapp[s[i] - 'a'][s[j] - 'a'][v];
                    mapp[s[i] - 'a'][s[j] - 'a'].erase(v);
                }
            }
        }
        cout << ans << '\n';
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
