#include <bits/stdc++.h>
#define OPENSTACK
#define Maxn 100005
#define Maxm 1000005
#define lowbit(x) x&(-x)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PI acos(-1.0)
#define random(x) (rand()%x)+1
#define LL long long
#define Inf (1LL<<62)
#define inf 0x3f3f3f3f
#define eps 1e-9
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
using namespace std;
using namespace chrono;
const int mod=1e9+7;
const int size=105;
double dp[Maxn],arr[Maxn],sum[Maxn];
int main()
{
    //input;output;  
    int n,k,_;
    scanf("%d",&_);
    for(int ncase=1;ncase<=_;ncase++){
        dp[0]=sum[0]=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lf",arr+i),dp[0]+=arr[i];
        sort(arr+1,arr+1+n);
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+arr[i];
        dp[0]/=n;
        for(int i=1;i<=k;i++){
            int pos=upper_bound(arr+1,arr+1+n,dp[i-1])-arr;
            dp[i]=(pos-1)*1.0/n*dp[i-1]+(sum[n]-sum[pos-1])/n;
        }
        printf("Case #%d: %.6lf\n",ncase,dp[k]);
    }
    return 0;
}