#ifdef WIN32
#include<bits/stdc++.h>
using namespace std;
#endif

#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
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
#endif
using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

#define pb push_back
struct Node
{
    string name;
    int time, amount;
    string city;
    Node(string name, int time, int amount, string city)
    {
        cerr << name << ' ' << time << ' ' << amount << ' ' << city << '\n';
        this->name = name;
        this->time = time;
        this->amount = amount;
        this->city = city;
    }
    bool operator<(Node &a) const
    {
        if (time == a.time)
        {
            if (name == a.name)
            {
                if (amount == a.amount)
                    return city < a.city;
                return amount < a.amount;
            }
            return name < a.name;
        }
        return time < a.time;
    }
};
class Solution
{
public:
    vector<string> invalidTransactions(vector<string> &transactions)
    {
        vector<Node> N;
        for (int i = 0; i < transactions.size(); ++i)
        {
            int cnt = 0, a = 0, b = 0;
            string name, city;
            for (int j = 0; j < transactions[i].size(); ++j)
            {
                auto c = transactions[i][j];
                if (transactions[i][j] == ',')
                    cnt++;
                else
                {
                    switch (cnt)
                    {
                    case 0:
                        name += c;
                        break;
                    case 1:
                        a = a * 10 + c - '0';
                        break;
                    case 2:
                        b = b * 10 + c - '0';
                        break;
                    case 3:
                        city += c;
                        break;
                    }
                }
            }
            N.pb(Node(name,
                      a,
                      b,
                      city));
        }
        vector<bool> valid(N.size(), true);
        for (int i = 0; i < N.size(); ++i)
        {
            if (N[i].amount > 1000)
                valid[i] = false;
            for (int j = i + 1; j < N.size(); ++j)
            {
                if (N[i].name == N[j].name)
                {
                    if (abs(N[i].time - N[j].time) <= 60 && N[i].city != N[j].city)
                    {
                        valid[i] = false;
                        valid[j] = false;
                    }
                }
            }
        }
        vector<string> ret;
        for (int i = 0; i < N.size(); ++i)
        {
            string s;
            if (!valid[i])
            {
                s = N[i].name + ',' + to_string(N[i].time) + ',' + to_string(N[i].amount) + ',' + N[i].city;
                ret.push_back(s);
            }
        }
        return ret;
    }
};