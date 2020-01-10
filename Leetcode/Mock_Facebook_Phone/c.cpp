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
    vector<string> answer;
    string digits;
    ll target;
    void recurse(int index, ll prevOperand, ll currentOperand, ll value, deque<string> &ops)
    {
        if (index == digits.length())
        {
            if (value == target && currentOperand == 0)
            {
                string str;
                for (auto elem : ops)
                    str += elem;
                answer.pb(str);
            }
            return;
        }
        currentOperand = currentOperand * 10 + digits[index] - '0';
        string current_val_rep = to_string(currentOperand);
        int len = digits.length();
        if (currentOperand > 0)
            recurse(index + 1, prevOperand, currentOperand, value, ops);

        ops.push_back("+");
        ops.push_back(current_val_rep);
        recurse(index + 1, currentOperand, 0, value + currentOperand, ops);
        ops.pop_back();
        ops.pop_back();

        if (ops.size())
        {
            ops.push_back("-");
            ops.push_back(current_val_rep);
            recurse(index + 1, -currentOperand, 0, value - currentOperand, ops);
            ops.pop_back();
            ops.pop_back();

            ops.push_back("*");
            ops.push_back(current_val_rep);
            recurse(index + 1, currentOperand * prevOperand, 0, value + currentOperand * prevOperand - prevOperand, ops);
            ops.pop_back();
            ops.pop_back();
        }
    }

public:
    vector<string> addOperators(string num, int target)
    {
        if (num.length() == 0)
            return {};
        this->target = target;
        this->digits = num;
        deque<string> stk;
        recurse(0, 0, 0, 0, stk);
        return answer;
    }
};

#ifdef LOCAL
int main()
{
    string num;
    int target;
    cin >> num >> target;
    Solution s;
    s.addOperators(num, target);
}
#endif
