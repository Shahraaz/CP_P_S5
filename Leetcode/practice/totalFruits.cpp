// Optimise
#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int> pokemons)
{
    int ret = 0;
    int lptr = 0, rptr = 0;
    int n = pokemons.size();
    map<int, int> cnt;
    auto addInt = [&](int x) {
        cnt[x]++;
    };
    auto subInt = [&](int x) {
        cnt[x]--;
        if (cnt[x] == 0)
            cnt.erase(x);
    };
    while (lptr < n)
    {
        while (rptr < n)
        {
            addInt(pokemons[rptr]);
            rptr++;
            if (cnt.size() == 3)
            {
                --rptr;
                subInt(pokemons[rptr]);
                break;
            }
        }
        ret = max(ret, rptr - lptr);
        subInt(pokemons[lptr]);
        lptr++;
    }
    return ret;
}

int main()
{
    cout << totalFruit({1, 2, 1}) << '\n';
    cout << totalFruit({0, 1, 2, 2}) << '\n';
    cout << totalFruit({1, 2, 3, 2, 2}) << '\n';
    cout << totalFruit({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}) << '\n';
}
