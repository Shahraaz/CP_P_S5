#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <list>
#include <cstdio>
#include <complex>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <iostream>

#define X real()
#define Y imag()
#define PB push_back
#define MP make_pair
#define FR(i,n) for( long long i = 0; i < n; i ++ )
#define FOR(i,a,n) for(long long i = a; i < n; i ++)
#define FREACH(it,v) for( typeof(v.end()) it = v.begin(); it != v.end(); it ++ )
#define EPS 1e-9
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;

int n1,n2;

int main()
{
    int n;
    bool b=false;
    while(cin >> n && n)
    {
        if(b) cout << endl;
        b=true;
        n1=0;
        n2=0;
        string s;
        int nmb;
        // pile n1, pile n2. n1 works like a stack, n2 works like a queue
        while(n--)
        {
            cin >> s >> nmb;
            if(s=="TAKE")
            {
                if(n1>=nmb)
                {
                    cout << "TAKE 1 " << nmb << endl;
                    n1-=nmb;
                }
                else
                {
                    if(n1!=0) cout << "TAKE 1 " << n1  << endl;
                    nmb-=n1;
                    cout << "MOVE 2->1 " << n2 << endl;                    
                    n1=n2;
                    n2=0;
                    cout << "TAKE 1 " << nmb << endl;
                    n1-=nmb;        
                }
            }
            else
            {
                n2+=nmb;
                cout << "DROP 2 " << nmb <<  endl;
            }            
        }
    }
}