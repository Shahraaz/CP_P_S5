// #include <bits/stdc++.h>
// using namespace std;

#include <stdio.h>
#include <string.h>

// #ifdef LOCAL
// #include "/debug.h"
// #else
// #define db(...)
// #endif

#define all(v) v.begin(), v.end()
#define pb push_back
#define ll long long;
const int MOD = 1000000007;
#define NAX 1004

typedef struct event
{
    int x1, y1, x2, y2;
} event;

event events[NAX];
int elements[NAX * 4];

int* lb(int *start, int *end, int x)
{
    
}

void solveCase()
{
    int n;
    // cin >> A >> B >> C;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        events[i].x1 = x1;
        events[i].y1 = y1;

        events[i].x2 = x2;
        events[i].y2 = y2;

        elements[4 * i] = x1;
        elements[4 * i + 1] = x2;
        elements[4 * i + 2] = y1;
        elements[4 * i + 3] = y2;
    }
    qsort(elements, elements + 4 * n);
    for (size_t i = 0; i < n; i++)
    {
        events[i].x1 = lb(elements, elements + 4 * n, events[i].x1) - elements;
        events[i].x2 = lb(elements, elements + 4 * n, events[i].x2) - elements;
        events[i].y1 = lb(elements, elements + 4 * n, events[i].y1) - elements;
        events[i].y2 = lb(elements, elements + 4 * n, events[i].y2) - elements;
    }
    // db(n, A, B, C);
    // printf("%d\n", solve(n));
    // cout << 3 * n - solve(0, 0, 0) << '\n';
}

int main()
{
    // #ifndef LOCAL
    //     ios_base::sync_with_stdio(0);
    //     cin.tie(0);
    // #endif
    int t = 1;
    // cin >> t;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; ++i)
        solveCase();
    return 0;
}