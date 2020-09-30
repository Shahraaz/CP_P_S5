#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INF = 1E18 + 7;

int n;
long long ans = 0, a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<long long>());
    for (int i = 2; i <= n; i++)
    {
        long long st = __lg(i - 1);
        long long cur = a[0] - (a[i - 1] + ans) + 1;
        long long eqa = (i == n ? INF : (a[i - 1] - a[i]) * (st + 1));
        long long tmp = (st == 0 ? INF : cur + cur / st - (cur % st == 0));
        // cout << eqa << " " << tmp << '\n';
        if (tmp <= eqa)
        {
            return cout << ans + tmp - 1, 0;
        }
        else
        {
            ans += eqa;
        }
    }
}