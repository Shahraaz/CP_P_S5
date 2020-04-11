// Optimise
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define MULTI_TEST
#ifdef LOCAL
#include "/home/shahraaz/bin/debug.h"
#else
#define db(...)
#define pc(...)
#endif

#define f first
#define s second
#define pb push_back
#define all(v) v.begin(), v.end()
auto TimeStart = chrono::steady_clock::now();
auto seed = TimeStart.time_since_epoch().count();
std::mt19937 rng(seed);
using ll = long long;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Random = std::uniform_int_distribution<T>;

const int NAX = 2e5 + 5, MOD = 1000000007;

class Solution
{
private:
public:
    Solution() {}
    ~Solution() {}
    void solveCase()
    {
        string prefix, suffix, total;
        int n;
        cin >> n;
        vector<pair<int, string>> strs(n);
        map<int, int> cnt;
        for (size_t i = 0; i < n; i++)
        {
            cin >> strs[i].s;
            strs[i].f = count(all(strs[i].s), '*');
            cnt[strs[i].f]++;
            if (strs[i].f == 0)
                total = strs[i].s;
        }
        if (cnt[0])
        {
            for (size_t i = 0; i < n; i++)
            {
                auto ok = [](string &txt, string &pat) -> bool {
                    int n = txt.size();
                    int m = pat.size();
                    if (m == 0)
                        return (n == 0);

                    int i = 0, j = 0, index_txt = -1, index_pat = -1;

                    while (i < n)
                    {

                        if (j < m && txt[i] == pat[j])
                        {
                            i++;
                            j++;
                        }

                        // For step - (3)
                        else if (j < m && pat[j] == '?')
                        {
                            i++;
                            j++;
                        }

                        // For step - (4)
                        else if (j < m && pat[j] == '*')
                        {
                            index_txt = i;
                            index_pat = j;
                            j++;
                        }

                        // For step - (5)
                        else if (index_pat != -1)
                        {
                            j = index_pat + 1;
                            i = index_txt + 1;
                            index_txt++;
                        }

                        // For step - (6)
                        else
                        {
                            return false;
                        }
                    }

                    // For step - (7)
                    while (j < m && pat[j] == '*')
                    {
                        j++;
                    }

                    // Final Check
                    if (j == m)
                    {
                        return true;
                    }

                    return false;
                };
                if (!ok(total, strs[i].s))
                {
                    cout << "*\n";
                    return;
                }
            }
            cout << total
                 << '\n';
        }
        else
        {
            for (size_t i = 0; i < n; i++)
            {
                int idx1, idx2;
                idx1 = idx2 = -1;
                for (size_t j = 0; j < strs[i].s.size(); j++)
                    if (strs[i].s[j] == '*')
                    {
                        idx1 = j;
                        break;
                    }
                    else
                    {
                        if (prefix.size() >= (j + 1))
                        {
                            if (prefix[j] != strs[i].s[j])
                            {
                                cout << "*\n";
                                return;
                            }
                        }
                        else
                            prefix += strs[i].s[j];
                    }
                reverse(all(strs[i].s));
                for (size_t j = 0; j < strs[i].s.size(); j++)
                    if (strs[i].s[j] == '*')
                    {
                        idx2 = strs[i].s.size() - j - 1;
                        break;
                    }
                    else
                    {
                        if (suffix.size() >= (j + 1))
                        {
                            if (suffix[j] != strs[i].s[j])
                            {
                                cout << "*\n";
                                return;
                            }
                        }
                        else
                            suffix += strs[i].s[j];
                    }
                reverse(all(strs[i].s));
                while (idx1 <= idx2)
                {
                    if (strs[i].s[idx1] != '*')
                        total += strs[i].s[idx1];
                    ++idx1;
                }
            }
            db(prefix, suffix, total);
            reverse(all(suffix));
            cout << prefix << total << suffix << '\n';
        }
    }
};

int32_t main()
{
#ifndef LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    Solution mySolver;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";
        mySolver.solveCase();
#ifdef TIME
        cerr << "Case #" << i << ": Time " << chrono::duration<double>(chrono::steady_clock::now() - TimeStart).count() << " s.\n";
        TimeStart = chrono::steady_clock::now();
#endif
    }
    return 0;
}