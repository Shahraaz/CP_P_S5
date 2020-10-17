#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int l = atoi(argv[2]);
    int p = atoi(argv[3]);

    string s;
    for (int i = 0; i < p; i++) {
        s += char(rnd.next('a', 'z'));
    }

    int st = rnd.next(0, n - l);
    for (int i = 0; i < st; i++) {
        cout << char(rnd.next('a', 'z'));
    }
    for (int i = 0; i < l; i++) {
        cout << s[i % p];
    }
    for (int i = st + l; i < n; i++) {
        cout << char(rnd.next('a', 'z'));
    }
    
    cout << endl;

    return 0;
}