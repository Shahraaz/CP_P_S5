#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n, p;
    scanf("%d", &n);
    vector<int> L(n), R(n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &L[i], &R[i]);
    scanf("%d", &p);
    vector<int> X(p);;
    for (int &x: X) scanf("%d", &x);

    
    auto pegs = [&](int i) { // O(p)
        return count_if(X.begin(), X.end(), [&](int x) { return L[i] <= x && x <= R[i]; });
    };
    
    for (int i = 0; i < n; ++i) {
        if (pegs(i) > 2) {
            printf("impossible\n");
            return 0;
        }
    }
    
    auto try_add = [&](int x) { // O(n*p)
        if (find(X.begin(), X.end(), x) != X.end())
            return false;
        X.push_back(x);
        for (int i = 0; i < n; ++i)
            if (pegs(i) > 2) {
                X.pop_back();
                return false;
            }
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (pegs(i) == 2) continue;
        int M1 = L[i]+1;
        while (find(X.begin(), X.end(), M1) != X.end()) ++M1;
        int M2 = M1 + 1;
        while (find(X.begin(), X.end(), M2) != X.end()) ++M2;
        for (int x: {R[i], L[i], M1, M2}) {
            if (try_add(x) && pegs(i) == 2) break;
        }
    }

    printf("%d\n", X.size() - p);
    for (int i = p; i < X.size(); ++i)
        printf("%d ", X[i]);
    printf("\n");
}
