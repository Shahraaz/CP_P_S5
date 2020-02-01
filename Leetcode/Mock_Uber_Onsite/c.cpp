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
    vector<int> owedArr;
    vector<int> owesArr;
    int transactionsDone;

public:
    int minTransfers(vector<vector<int>> &transactions)
    {
        owedArr.clear();
        owesArr.clear();
        transactionsDone = INT_MAX;
        map<int, int> transMap;
        for (auto &tran : transactions)
        {
            transMap[tran[0]] -= tran[2];
            transMap[tran[1]] += tran[2];
        }
        for (auto &perSon : transMap)
        {
            if (perSon.s == 0)
                continue;
            if (perSon.s > 0)
                owesArr.pb(perSon.s);
            else
                owedArr.pb(-perSon.s);
        }
        findMinTransactionsNeeded(0, 0);
        return transactionsDone;
    }
    void findMinTransactionsNeeded(int owedIndex, int currTransactionDone)
    {
        // cout << owedIndex << ' ' << currTransactionDone << '\n';
        // pc(owesArr, owedArr);
        if (owedIndex == owedArr.size())
        {
            transactionsDone = min(transactionsDone, currTransactionDone);
            return;
        }
        for (int i = 0; i < owesArr.size(); i++)
        {
            if (owesArr[i] == 0)
                continue;
            int temp = owesArr[i];
            if (owedArr[owedIndex] <= temp)
            {
                owesArr[i] -= owedArr[owedIndex];
                findMinTransactionsNeeded(owedIndex + 1, currTransactionDone + 1);
            }
            else
            {
                int tempOwed = owedArr[owedIndex];
                owedArr[owedIndex] -= owesArr[i];
                owesArr[i] = 0;
                findMinTransactionsNeeded(owedIndex, currTransactionDone + 1);
                owedArr[owedIndex] = tempOwed;
            }
            owesArr[i] = temp;
        }
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
        ;
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}
#endif