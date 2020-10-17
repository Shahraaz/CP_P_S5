#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    for (int i = 0; i < n; i++) {
        int popcnt = 0;
        int x = i;
        while (x) {
            popcnt++;
            x &= (x - 1);
        }
        cout << char(popcnt % 2 + 'a');
    }
    cout << endl;

    return 0;
}