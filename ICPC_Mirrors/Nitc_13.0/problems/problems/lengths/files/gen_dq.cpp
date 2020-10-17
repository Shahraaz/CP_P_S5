#include "testlib.h"
#include <functional>
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    string s(n, 0);

    function<void(int, int, int)> gen = [&](int l, int r, int d) {
        if (l > r) {
            return;
        }
        int m = (l + r) >> 1;
        s[m] = char(d + 'a');
        gen(l, m - 1, d + 1);
        gen(m + 1, r, d + 1);
    };

    gen(0, n - 1, 0);
    cout << s << endl;

    return 0;
}