#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    string s = "";
    int i = 0;
    int c = 0;
    while (int(s.size()) != n) {
        int x = ++i;
        int popcnt = 0;
        while (x) {
            popcnt++;
            x &= (x - 1);
        }
        if (popcnt % 2) {
            c++;
        } else {
            s += char(c + 'a');
            c = 0;
        }
    }
    cout << s << endl;

    return 0;
}