//Optimise
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
auto TimeStart = chrono::steady_clock::now();

const int NAX = 2e5 + 10, MOD = 1000000007;

vector<ll> factors(ll x)
{
    vector<ll> ret;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
        {
            ret.pb(i), ret.pb(x / i);
            break;
        }
    return ret;
}

void solveCase(int caseNo)
{
    string n;
    cin >> n;
    int l;
    cin >> l;
    vector<ll> cipheres(l);
    vector<ll> primes;
    vector<vector<ll>> tempList;
    for (auto &x : cipheres)
    {
        cin >> x;
        auto fact = factors(x);
        for (auto y : fact)
            primes.pb(y);
        tempList.pb(fact);
    }
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    // pc(primes);
    // db(primes.size());
    vector<vector<char>> candies;
    for (auto &fact : tempList)
    {
        vector<char> temp;
        for (auto y : fact)
            temp.pb(lower_bound(primes.begin(), primes.end(), y) - primes.begin() + 'A');
        // pc(temp);
        candies.pb(temp);
    }
    vector<char> res;
    char curr = candies[0][0], other = candies[0][1];
    res.pb(curr);
    db(curr);
    bool skip = false;
    for (int i = 1; i < cipheres.size(); ++i)
    {
        int a = count(candies[i].begin(), candies[i].end(), other);
        pc(candies[i]);
        db(other, i, a);
        if (a == 0)
        {
            skip = true;
            break;
        }
        else if (a == 1)
        {
            res.pb(other);
            for (auto y : candies[i])
                if (y != other)
                {
                    other = y;
                    break;
                }
        }
        else
        {
            res.pb(other);
        }
    }
    if (!skip)
    {
        res.pb(other);
        for (auto elem : res)
            cout << elem;
        cout << '\n';
        return;
    }

    res.clear();

    curr = candies[0][1], other = candies[0][0];
    res.pb(curr);
    db(curr);
    skip = false;
    for (int i = 1; i < cipheres.size(); ++i)
    {
        int a = count(candies[i].begin(), candies[i].end(), other);
        pc(candies[i]);
        db(other, i, a);
        if (a == 0)
        {
            skip = true;
            break;
        }
        else if (a == 1)
        {
            res.pb(other);
            for (auto y : candies[i])
                if (y != other)
                {
                    other = y;
                    break;
                }
        }
        else
        {
            res.pb(other);
        }
    }
    if (!skip)
    {
        res.pb(other);
        for (auto elem : res)
            cout << elem;
        cout << '\n';
        return;
    }
}

int main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        solveCase(i);
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}