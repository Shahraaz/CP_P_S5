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
int n, q;
vector<pair<int, int>> seg;
vector<int> val;

bool can(int x)
{
    db(x);
    val.assign(q, 0);
    set<pair<int, int>> s;
    int last = 0, cur = 0;
    for (auto pp : seg)
    {
        int l = pp.first, r = pp.second;
        db(l, r);
        while (!s.empty())
        {
            db("One", last);
            pc(val, s);
            auto it = s.begin();
            if (it->f <= l)
            {
                val[it->s] += max(it->f - last, 0);
                last = max(last, it->f);
                s.erase(it);
            }
            else
                break;
        }
        db("Two", last);
        pc(val, s);
        if (last < l)
        {
            if (!s.empty())
                val[s.begin()->s] += l - last;
            last = l;
            db("Three", last);
            pc(val);
        }
        pair<int, int> now = {r, cur++};
        s.insert(now);
        auto it = s.lower_bound(now);
        if (it == s.begin())
            continue;
        --it;
        while (true)
        {
            db("Four");
            pc(s, val);
            if (val[it->s] >= x)
            {
                if (it == s.begin())
                {
                    s.erase(it);
                    break;
                }
                else
                {
                    auto beg = it;
                    --it;
                    s.erase(beg);
                }
            }
            else
                break;
        }
        db("Five");
        pc(s, val);
    }
    while (!s.empty())
    {
        db("Six");
        pc(s, val);
        auto it = s.begin();
        val[it->s] += max(it->f - last, 0);
        last = max(last, it->f);
        s.erase(it);
    }
    db("Seven");
    pc(s, val);
    cerr << last << endl;
    bool ret = 1;
    int w = 0;
    for (int u : val)
    {
        if (u < x)
        {
            ret = 0;
        }
        db(u, seg[w].first, seg[w].second);
        ++w;
    }
    return ret;
}

void solveCase(int caseNo)
{
    cin >> n >> q;
    int low = 0, high = n, ans = 0;
    seg.resize(q);
    for (int i = 0; i < q; ++i)
    {
        cin >> seg[i].f >> seg[i].s;
        --seg[i].f;
        high = min(high, seg[i].s - seg[i].f);
    }
    sort(seg.begin(), seg.end());
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (can(mid))
            ans = max(ans, mid), low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Case #" << caseNo << ": ";
    cout << ans << '\n';
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
        cerr << "Case #" << i << ": Time" << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}