#include <bits/stdc++.h>

#ifdef LOCAL
#include "/debug.h"
#else
#define db(...)
#endif
using namespace std;
long double arr[500];
int n;
void func(int dim, long double dis)
{
    db(dim, dis);
    int i;
    for (i = 1; i <= n; i++)
    {
        if (i != dim)
            printf("%.9Lf ", arr[i]);
        else
            printf("%.9Lf ", dis);
    }
    cout << endl;
    if (dim == 0)
        return;
    long double c = dis / dim ;
    arr[dim] = -c;
    long double a = sqrt(dis * dis - c * c);
    db(c, a);
    func(dim - 1, a);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            arr[i] = 0.000;
        func(n, 1.000);
        cout << endl;
    }
    return 0;
}