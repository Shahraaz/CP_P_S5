#include <bits/stdc++.h>
using namespace std;
#define Debug
#ifdef Debug
#define db(...) ZZ(#__VA_ARGS__, __VA_ARGS__);
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
#endif

using ll = long long;
#define f first
#define s second
#define pb push_back
const long long mod = 1000000007;

const int nax = 1e5 + 10;
using pii = pair<int, int>;
class DinnerPlates
{
    stack<int> S[nax];
    set<int> leftNonFull;
    set<int> rightNonEmpty;
    int cap;

public:
    DinnerPlates(int capacity)
    {
        cap = capacity;
        for (int i = 0; i < nax; ++i)
            leftNonFull.insert(i);
    }
    void push(int val)
    {
        auto left = *leftNonFull.begin();
        S[left].push(val);
        rightNonEmpty.insert(left);
        if (S[left].size() == cap)
            leftNonFull.erase(leftNonFull.begin());
    }
    int pop()
    {
        if (rightNonEmpty.empty())
            return -1;
        int ind = *rightNonEmpty.rbegin();
        auto ret = S[ind].top();
        S[ind].pop();
        if (S[ind].size() == (cap - 1))
            leftNonFull.insert(ind);
        if (S[ind].size() == 0)
            rightNonEmpty.erase(--rightNonEmpty.end());
        return ret;
    }

    int popAtStack(int index)
    {
        if (S[index].size())
        {
            auto ret = S[index].top();
            S[index].pop();
            if (S[index].size() == (cap - 1))
                leftNonFull.insert(index);
            if (S[index].size() == 0)
                rightNonEmpty.erase(index);
            return ret;
        }
        return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */