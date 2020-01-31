// Optimise
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
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
    string formula;

    int getCnt(int &pos)
    {
        cout << "GetCnt: " << pos << ' ';
        if (pos == formula.length())
        {
            int ret = 1;
            return 1;
        }
        if ('0' <= formula[pos] && formula[pos] <= '9')
            ;
        else
        {
            int ret = 1;
            return 1;
        }
        int ret = 0;
        while (pos < formula.length() && '0' <= formula[pos] && formula[pos] <= '9')
        {
            ret = ret * 10 + (formula[pos] - '0');
            ++pos;
        }
        return ret;
    }

    string extractName(int &pos)
    {
        cout << "ExtractName: " << pos << ' ';
        string str;
        if (pos == formula.length() || !isupper(formula[pos]))
        {
            return str;
        }
        str += formula[pos++];
        while (pos < formula.length() && islower(formula[pos]))
            str += formula[pos++];
        return str;
    }

    map<string, int> Solve(int &pos)
    {
        map<string, int> ret;
        if (pos == formula.length() || formula[pos] == ')')
            return ret;
        int opCnt = 0;
        int currCnt = 0;
        string currSym = "";
        bool way = false;
        for (int i = pos; i < formula.length();)
        {
            pos = i;
            if (formula[i] == '(')
            {
                auto temp = Solve(i);
                int Cnt = getCnt(i);
                for (auto &elem : temp)
                    ret[elem.f] += elem.s * Cnt;
                pos = i;
            }
            else if (isupper(formula[i]))
            {
                currSym = extractName(i);
                ret[currSym] += getCnt(i);
                pos = i;
            }
            else if (formula[i] == ')')
            {
                pos++;
                break;
            }
        }
        return ret;
    }

public:
    string countOfAtoms(string formula)
    {
        this->formula = formula;
        auto res = Solve(0);
        string ret;
        for (auto &elem : res)
        {
            ret += elem.f;
            if (elem.s > 1)
                ret += to_string(elem.s);
        }
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution S;
    for (int i = 1; i <= t; ++i)
    {
        string str;
        cin >> str;
        cout << S.countOfAtoms(str) << '\n';
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif