#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll int
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define deb(x) cout << #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define setbits(n) __builtin_popcountll(n)
#define mkunique(a) a.resize(unique(a.begin(), a.end()) - a.begin()); //need to sort
#define print(s)          \
    for (ll u : s)        \
        cout << u << " "; \
    cout << "\n";
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;

// const int N=1e5+10;
#define N 50010

int p[N], mark[N];

struct Graph
{
    struct Node *head[N];
};

struct Node
{
    int dest;
    struct Node *next;
};

struct Edge
{
    int src, dest;
};

struct Graph *createGraph(struct Edge edges[], int n)
{
    unsigned i;

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    for (i = 0; i < N; i++)
    {
        graph->head[i] = NULL;
    }

    for (i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        // printf("%d %d %d\n", i, src, dest);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;

        newNode->next = graph->head[src];

        graph->head[src] = newNode;
    }

    return graph;
}

void printGraph(struct Graph *graph)
{
    int i;
    for (i = 0; i < N; i++)
    {
        struct Node *ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

void dfs(struct Graph *graph, ll v, ll par)
{
    p[v] = par;

    struct Node *ptr = graph->head[v];
    while (ptr != NULL)
    {
        if (ptr->dest != par)
            dfs(graph, ptr->dest, v);
        ptr = ptr->next;
    }
}

int main()
{

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    // ll TT=clock();

    ll t;
    scanf("%d", &t);
    // printf("t = %d\n", t);
    while (t--)
    {
        ll n;
        scanf("%d", &n);
        // printf("n = %d\n", n);

        struct Edge edges[2 * n - 2];
        for (int i = 0; i + 1 < n; ++i)
        {
            scanf("%d %d", &edges[i].src, &edges[i].dest);

            edges[i].src--;
            edges[i].dest--;

            // printf("%d %d\n", edges[i].src, edges[i].dest);

            edges[n - 1 + i].src = edges[i].dest;
            edges[n - 1 + i].dest = edges[i].src;
        }
        // printf("edges taken\n");

        struct Graph *graph = createGraph(edges, 2 * n - 2);

        dfs(graph, 0, -1);
        ll m;
        // cin >> m;
        scanf("%d", &m);
        // printf("m = %d\n", m);
        ll tot = n;
        // vector<ll> mark(n);
        memset(mark, -1, sizeof mark);

        while (m--)
        {
            ll v;
            // cin >> v;
            scanf("%d", &v);
            // printf("v = %d\n", v);
            v--;
            while (v != -1)
            {
                if (mark[v] == 1)
                    break;
                mark[v] = 1;
                tot--;
                v = p[v];
            }
            // cout << tot << "\n";
            printf("%d\n", tot);
        }
    }

    // cerr<<"\n\nTIME: "<<(long double)(clock()-TT)/CLOCKS_PER_SEC<<" sec\n";
    // TT = clock();
    return 0;
}