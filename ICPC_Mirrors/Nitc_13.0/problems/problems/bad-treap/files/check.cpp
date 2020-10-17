#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

// Larger sin(x) <=> Larger quasiSin(x)
long double quasiSin(int x) {
    long double t = x / (2 * 3.14159265358979323846264338328L) + 0.25;
    return abs(t - roundl(t));
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    vector<int> x;
    x.resize(n);
    for (int i = 0; i < n; i++) x[i] = ouf.readInt();
    sort(x.begin(), x.end());
    vector<int> stack;
    vector<int> treeHeights;
    size_t height = 0;
    for (int i = 0; i < n; i++) {
        if ((i > 0) && (x[i - 1] == x[i])) quitf(_wa, "Duplicate x: %d", x[i]);
        int leftTree = 0;
        int x1 = x[i];
        while (!stack.empty()) {
            int x0 = stack.back();
            long double diff1 = sin(x0) - sin(x1);
            long double diff2 = quasiSin(x0) - quasiSin(x1);
            if (diff1 * diff2 < 0) quitf(_fail, "Failed sin comparison of %d and %d", x0, x1);
            if (diff2 == 0) quitf(_fail, "Failed quasiSin concept in %d and %d", x0, x1);
            if (diff2 > 0) break;
            int t = treeHeights.back();
            stack.pop_back();
            treeHeights.pop_back();
            leftTree = max(leftTree + 1, t);
        }
        stack.push_back(x1);
        treeHeights.push_back(leftTree + 1);
        height = max(height, stack.size() + leftTree);
    }
    if (height < n) quitf(_wa, "Height is too small: %d < %d", height, n);
    if (height > n) quitf(_fail, "Failed tree height calculaction: %d > %d", height, n);
    quitf(_ok, "Height %d", height);
}
