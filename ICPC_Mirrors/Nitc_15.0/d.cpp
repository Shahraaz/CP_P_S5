#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(), a.end()) - a.begin());
const ll mod = 1e9 + 7;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = clock();

    string s;
    cin >> s;
    ll n = s.size();
    n /= 2;
    map<char, ll> mpp;
    vector<pair<ll, char>> a;
    for (ll i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }
    if (mpp.size() == 1)
    {
        cout << "NO";
        return 0;
    }
    for (auto p : mpp)
        a.pb({p.second, p.first});
    sort(a.begin(), a.end(), greater<pair<ll, char>>());
    if (s.size() == 2)
    {
        cout << "YES\n";
        cout << s;
        return 0;
    }
    if (a.size() == 2)
    {
        if (a[0].first > n && a[1].first == 2)
        {
            cout << "NO";
            return 0;
        }
        cout << "YES\n";
        for (ll i = 0; i < n; i++)
            cout << a[0].second;
        cout << a[1].second;
        for (ll i = 0; i < a[0].first - n; i++)
            cout << a[0].second;
        for (ll i = 0; i < a[1].first - 1; i++)
            cout << a[1].second;
        return 0;
    }
    cout << "YES\n";
    if (a[0].first > n)
    {
        for (ll i = 0; i < n; i++)
            cout << a[0].second;
        for (ll i = 1; i < a.size() - 1; i++)
        {
            for (ll j = 0; j < a[i].first; j++)
                cout << a[i].second;
        }
        for (ll i = 0; i < a[0].first - n; i++)
            cout << a[0].second;
        for (ll i = 0; i < a[a.size() - 1].first; i++)
            cout << a[a.size() - 1].second;
    }
    else
    {
        for (ll i = 0; i < a.size(); i++)
        {
            for (ll j = 0; j < a[i].first; j++)
                cout << a[i].second;
        }
    }

    cerr << "\n\nTIME: " << (double)(clock() - T) / CLOCKS_PER_SEC << " sec\n";
    T = clock();
    return 0;
}