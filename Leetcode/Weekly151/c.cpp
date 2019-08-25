#include<bits/stdc++.h>
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

const int nax = 2e5 + 10;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *curr;
        curr = head;
        int cnt = 0;
        ListNode *next = curr;
        bool pro = true;
        while (pro)
        {
            pro = false;
            next = head;
            while (next != NULL)
            {
                cnt += next->val;
                next = next->next;
                if (cnt == 0)
                {
                    pro = true;
                    head = next;
                    break;
                }
            }
        }
        curr = head;
        while (curr != NULL)
        {
            int cnt = 0;
            ListNode *next = curr->next;
            bool pro = true;
            if (next == NULL)
                break;
            while (next != NULL)
            {
                cnt += next->val;
                next = next->next;
                if (cnt == 0)
                {
                    pro = false;
                    curr->next = next;
                    break;
                }
            }
            if (pro)
                curr = curr->next;
        }
        return head;
    }
};