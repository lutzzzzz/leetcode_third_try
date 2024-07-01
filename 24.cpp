#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *cur = dummyHead;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode *tmp_pre = cur->next;
            ListNode *tmp_cur = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp_pre;
            cur->next->next->next = tmp_cur;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};