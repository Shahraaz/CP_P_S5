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

const int nax = 2e5 + 10;

class ChristmasSongBroadcast
{
    int n;

public:
    int minimizeCost(int T, vector<int> A, vector<int> B, vector<string> directCost)
    {
        n = A.size();
        vector<int> minCosts(n);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
        vector<ll> dist(n, mod);
        for (int i = 0; i < n; ++i)
        {
            minCosts[i] = B[i];
            ll maxi = (ll)(T - 1) * A[i] + B[i];
            if (maxi >= mod)
            {
                int point = ceil(double(mod - B[i]) / A[i]);
                minCosts[i] = min(minCosts[i], int(((ll)point * A[i] + B[i]) % mod));
            }
            Q.push({minCosts[i], i});
            dist[i] = minCosts[i];
        }
        ll ret = 0;
        vector<bool> vis(n);
        pc(dist);
        while (!Q.empty())
        {
            auto top = Q.top();
            Q.pop();
            if (vis[top.s])
                continue;
            db(top);
            vis[top.s] = true;
            ret += top.f;
            for (int i = 0; i < n; ++i)
                if (i != top.s)
                    if (!vis[i])
                        if ((directCost[top.s][i]) < dist[i])
                        {
                            dist[i] = (directCost[top.s][i]);
                            Q.push({dist[i], i});
                        }
        }
        return ret;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector<int> p1, vector<int> p2, vector<string> p3, bool hasAnswer, int p4)
{
    cout << "Test " << testNum << ": [" << p0 << ","
         << "{";
    for (int i = 0; int(p1.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}"
         << ","
         << "{";
    for (int i = 0; int(p2.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}"
         << ","
         << "{";
    for (int i = 0; int(p3.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << "\"" << p3[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    ChristmasSongBroadcast *obj;
    int answer;
    obj = new ChristmasSongBroadcast();
    clock_t startTime = clock();
    answer = obj->minimizeCost(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p4;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    int p0;
    vector<int> p1;
    vector<int> p2;
    vector<string> p3;
    int p4;

    {
        // ----- test 0 -----
        p0 = 1000000007;
        int t1[] = {1, 10, 100};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {7, 7, 7};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        string t3[] = {"-AA", "A-A", "AA-"};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 0;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 1;
        int t1[] = {1, 1, 1};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1600, 1500, 1700};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        string t3[] = {"-01", "0-A", "1A-"};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 1597;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 2;
        int t1[] = {100, 100, 100, 100};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {0, 35, 999999910, 123456789};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        string t3[] = {"-01z", "0-Az", "1A-z", "zzz-"};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 160;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 1;
        int t1[] = {47};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        int t2[] = {1000000006};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        string t3[] = {"-"};
        p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
        p4 = 1000000006;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!