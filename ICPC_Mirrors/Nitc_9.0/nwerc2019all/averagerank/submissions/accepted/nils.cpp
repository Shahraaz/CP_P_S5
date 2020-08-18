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

vector<ll> last_updated;
vector<ll> sum_of_ranks;
vector<ll> current_rank;

vector<ll> points;
vector<ll> old_sum;
vector<ll> answer;

int n,d;

ll get_sum(int p, ll t){
    return sum_of_ranks[p] + current_rank[p] * (t - last_updated[p]);
}

int main()
{
    cin >> n >> d;

    last_updated.assign(d+1,0);
    sum_of_ranks.assign(d+1,0);
    current_rank.assign(d+1,0);

    points.assign(n,0);
    old_sum.assign(n,0);
    answer.assign(n,0);

    for(ll c1 = 0; c1 < d; c1++){
        int k;
        cin >> k;
        for(int c2 = 0; c2 < k; c2++){
            int i;
            cin >> i;
            i--;
            answer[i] += get_sum(points[i], c1) - old_sum[i];
            sum_of_ranks[points[i]] = get_sum(points[i], c1);
            last_updated[points[i]] = c1;
            current_rank[points[i]]++;
            points[i]++;
            old_sum[i] = get_sum(points[i], c1);
        }
    }

    for(int c1 = 0; c1 < n; c1++){
        answer[c1] += get_sum(points[c1],d) - old_sum[c1];
        cout << setprecision(6) << fixed << double(answer[c1]) / double(d) + 1.0 << "\n";
    }

    return 0;
}
