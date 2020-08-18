#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

int n,d;

// O(nd + d^2) without log-factor.

vl points, people, better, answer;

int main()
{
    cin >> n >> d;

    answer.assign(n,0);
    points.assign(n,0);
    people.assign(d+1,0);
    better.assign(d+1,0);

    for(ll c1 = 0; c1 < d; c1++){
        int k;
        cin >> k;
        for(int c2 = 0; c2 < k; c2++){
            int i;
            cin >> i;
            i--;
            people[points[i]]--;
            points[i]++;
            people[points[i]]++;
        }
        int sum = 0;
        for(int c2 = d; c2 >= 0; c2--){
            better[c2] = sum;
            sum += people[c2];
        }
        
        // Here is the slow part:
        for(int c2 = 0; c2 < n; c2++){
            answer[c2] += better[points[c2]];
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        cout << setprecision(6) << fixed << double(answer[c1]) / double(d) + 1.0 << "\n";
    }

    return 0;
}
