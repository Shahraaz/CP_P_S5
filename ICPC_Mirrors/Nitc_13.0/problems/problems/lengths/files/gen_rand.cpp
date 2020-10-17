#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);

    int n = rnd.next(1, N);
    for (int i = 0; i < n; i++) {
        cout << char(rnd.next('a', 'z'));
    }
    cout << endl;

    return 0;
}