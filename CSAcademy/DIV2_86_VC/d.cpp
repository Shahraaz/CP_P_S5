//Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define MULTI_TEST
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.f != b.f)
        return a.f < b.f;
    return a.s > b.s;
}

void solveCase(int caseNo)
{
    int h, q;
    cin >> h >> q;
    vector<pair<int, int>> holes(q);
    bool ok = false;
    for (auto &x : holes)
    {
        cin >> x.f >> x.s;
        ok |= (x.s == 0);
    }
    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }
    sort(holes.begin(), holes.end(), cmp);
    priority_queue<int> Q;
    using ld = long double;
    ld H = h, it = 0;
    ld T = holes[0].f;
    while (H > 0 && it < q)
    {
        while (!Q.empty() && Q.top() >= H)
            Q.pop();
        if (Q.empty())
        {
            T = holes[it].f;
            Q.push(holes[it].s);
            ++it;
            continue;
        }
        if (holes[it].f == T)
        {
            Q.push(holes[it].s);
            ++it;
            continue;
        }
        if (it == q)
            break;
        int highest = Q.top();
        int sz = Q.size();
        ld until = (ld)(H - highest) / sz;
        ld dif = holes[it].f;
        dif -= T;
        if (until <= dif)
        {
            Q.pop();
            H = highest;
            T += until;
        }
        else
        {
            T += dif;
            H -= dif * sz;
            Q.push(holes[it].s);
            ++it;
        }
    }
    while (!Q.empty() && H > 0)
    {
        int highest = Q.top();
        if (highest >= H)
            Q.pop();
        else
        {
            int sz = Q.size();
            ld until = (ld)(H - highest) / sz;
            H = highest;
            T += until;
            Q.pop();
        }
    }
    cout << fixed << setprecision(9) << T << '\n';
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
        solveCase(i);
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}