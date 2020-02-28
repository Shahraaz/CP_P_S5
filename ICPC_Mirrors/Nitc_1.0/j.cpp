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
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        int n;
        cin >> n;
        map<string, int> countIfSelectionFinishesHere;
        map<string, int> idxOfString;
        vector<int> prevIdx(n, -1);
        cin.ignore();
        for (int i = 0; i < n; i++)
        {
            string str;
            getline(cin, str);
            stringstream sin(str);
            string myId, currMsg;
            sin >> myId;
            myId = myId.substr(0, myId.size() - 1);
            if (countIfSelectionFinishesHere.count(myId) == 0)
            {
                countIfSelectionFinishesHere[myId] = 1;
                idxOfString[myId] = i;
            } // cout << myId << ' ';
            while (sin >> currMsg)
            {
                // cout << currMsg << ' ';
                if (myId == currMsg)
                    continue;
                if (currMsg[0] == '@')
                {
                    if (countIfSelectionFinishesHere[currMsg] + 1 > countIfSelectionFinishesHere[myId])
                    {
                        countIfSelectionFinishesHere[myId] = countIfSelectionFinishesHere[currMsg] + 1;
                        prevIdx[i] = idxOfString[currMsg];
                        idxOfString[myId] = i;
                    }
                }
            }
            // cout << '\n';
        }

        int idx = -1;
        int ans = 0;

        for (auto &msg : countIfSelectionFinishesHere)
        {
            if (ans < msg.s)
            {
                ans = msg.s;
                idx = idxOfString[msg.f];
            }
        }
        cout << ans << '\n';

        stack<int> st;

        while (idx >= 0)
        {
            st.push(idx);
            idx = prevIdx[idx];
        }

        while (!st.empty())
        {
            cout << st.top() + 1 << ' ';
            st.pop();
        }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    freopen("join.in", "r", stdin);
    freopen("join.out", "w", stdout);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
