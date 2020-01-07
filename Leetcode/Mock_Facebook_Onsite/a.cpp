#include <bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
#define pc(...) PC(#__VA_ARGS__, __VA_ARGS__);
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &p)
{
    out << '[' << p.first << ", " << p.second << ']';
    return out;
}
template <typename Arg>
void PC(const char *name, Arg &&arg)
{
    std::cerr << name << " { ";
    for (const auto &v : arg)
        cerr << v << ' ';
    cerr << " }\n";
}
template <typename Arg1>
void ZZ(const char *name, Arg1 &&arg1)
{
    std::cerr << name << " = " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    std::cerr.write(names, comma - names) << " = " << arg1;
    ZZ(comma, args...);
}
#else
#define db(...)
#define pc(...)
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 2e5 + 10;

class Solution
{
    set<string> validExpressions;
    int minimumRemoved;
    void reset()
    {
        validExpressions.clear();
        minimumRemoved = INT_MAX;
    }
    void recurse(string &s, int index, int leftCount, int rightCount, string expression, int removedCount)
    {
        if (index == s.length())
        {
            if (leftCount == rightCount)
            {
                if (removedCount < minimumRemoved)
                {
                    reset();
                    minimumRemoved = removedCount;
                }
                if (removedCount == minimumRemoved)
                    validExpressions.insert(expression);
            }
        }
        else
        {
            char currentCharecter = s[index];
            if (currentCharecter != '(' && currentCharecter != ')')
                recurse(s, index + 1, leftCount, rightCount, expression + currentCharecter, removedCount);
            else
            {
                recurse(s, index + 1, leftCount, rightCount, expression, removedCount + 1);
                if (currentCharecter == '(')
                    recurse(s, index + 1, leftCount + 1, rightCount, expression + currentCharecter, removedCount);
                else if (rightCount < leftCount)
                    recurse(s, index + 1, leftCount, rightCount + 1, expression + currentCharecter, removedCount);
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string s)
    {
        reset();
        recurse(s, 0, 0, 0, "", 0);
        vector<string> ret;
        for (auto elem : validExpressions)
            ret.pb(elem);
        return ret;
    }
};

#ifdef LOCAL
int main()
{
    Solution s;
    string str;
    cin >> str;
    s.removeInvalidParentheses(str);
}
#endif