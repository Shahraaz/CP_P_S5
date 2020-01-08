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

class UnionFind
{ // OOP style
private:
    vector<int> p, rank, setSize; // remember: vi is vector<int>
    int numSets;

public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    bool unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
            return true;
        }
        return false;
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

class ChristmasSongBroadcast
{
    int minimumCost(int A, int B, int T)
    {
        int best = B, current = B, tower = 0;
        while (tower < T)
        {
            int jump = (mod - 1 - current) / A + 1;
            tower += jump;
            if (tower >= T)
                return best;
            current = (current + jump * A) % mod;
            best = min(best, current);
        }
        return best;
    }

public:
    int minimizeCost(int T, vector<int> A, vector<int> B, vector<string> directCost)
    {
        int n = A.size();
        UnionFind U(n + 1);
        vector<pair<int, pair<int, int>>> edges;
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                if (i != j)
                    edges.pb({directCost[i][j], {i, j}});
        for (size_t i = 0; i < n; i++)
            edges.pb({minimumCost(A[i], B[i], T), {i, n}});
        sort(edges.begin(), edges.end());
        int res = 0;
        for (auto edge : edges)
            if(U.unionSet(edge.s.f,edge.s.s))
                res += edge.f;
        return res;
    }
};

#ifndef LOCAL
//<%:testing-code%>
#endif

#ifdef LOCAL
int main()
{
    return 0;
}
#endif

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!