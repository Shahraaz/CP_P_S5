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

const int NAX = 2e5 + 5, MOD = 1000000007;

void solveCase(int caseNo)
{
    db(caseNo);
    int N, R, C, Sr, Sc;
    cin >> N >> R >> C >> Sr >> Sc;
    string steps;
    cin >> steps;
    map<pair<int, int>, pair<int, int>> destLeft;
    map<pair<int, int>, pair<int, int>> destRight;
    map<pair<int, int>, pair<int, int>> destUp;
    map<pair<int, int>, pair<int, int>> destDown;
    set<pair<int, int>> vis;
    destDown[{Sr, Sc}] = {Sr + 1, Sc};
    destUp[{Sr, Sc}] = {Sr - 1, Sc};
    destLeft[{Sr, Sc}] = {Sr, Sc - 1};
    destRight[{Sr, Sc}] = {Sr, Sc + 1};
    vis.insert({Sr, Sc});
    for (int i = 0; i < steps.size(); i++)
    {
        db(i, Sr, Sc, steps[i]);
        stack<pair<int, int>> path;
        switch (steps[i])
        {
        case 'N':
            db("startNorth");
            while (vis.find({Sr, Sc}) != vis.end())
            {
                path.push({Sr, Sc});
                auto next = destUp[{Sr, Sc}];
                Sr = next.f;
                Sc = next.s;
                db(next);
            }
            db("stopNorth");
            while (path.size())
            {
                auto top = path.top();
                path.pop();
                destUp[top] = {Sr, Sc};
            }
            break;
        case 'S':
            db("startSouth");
            while (vis.find({Sr, Sc}) != vis.end())
            {
                path.push({Sr, Sc});
                auto next = destDown[{Sr, Sc}];
                Sr = next.f;
                Sc = next.s;
                db(next);
            }
            db("stopSouth");
            while (path.size())
            {
                auto top = path.top();
                path.pop();
                destDown[top] = {Sr, Sc};
            }
            break;
        case 'E':
            db("startEast");
            while (vis.find({Sr, Sc}) != vis.end())
            {
                path.push({Sr, Sc});
                auto next = destRight[{Sr, Sc}];
                Sr = next.f;
                Sc = next.s;
                db(next);
            }
            db("stopEast");
            while (path.size())
            {
                auto top = path.top();
                path.pop();
                destRight[top] = {Sr, Sc};
            }
            break;
        case 'W':
            db("startWest");
            while (vis.find({Sr, Sc}) != vis.end())
            {
                path.push({Sr, Sc});
                auto next = destLeft[{Sr, Sc}];
                Sr = next.f;
                Sc = next.s;
                db(next);
            }
            db("stopWest");
            while (path.size())
            {
                auto top = path.top();
                path.pop();
                destLeft[top] = {Sr, Sc};
            }
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        destDown[{Sr, Sc}] = {Sr + 1, Sc};
        destUp[{Sr, Sc}] = {Sr - 1, Sc};
        destLeft[{Sr, Sc}] = {Sr, Sc - 1};
        destRight[{Sr, Sc}] = {Sr, Sc + 1};
        vis.insert({Sr, Sc});
        db("EndPos", Sr, Sc);
    }
    cout << "Case #" << caseNo << ": " << Sr << ' ' << Sc << '\n';
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
