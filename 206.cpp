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
    ListNode *reverse(ListNode *pre, ListNode *cur)
    {
        if (cur == NULL)
        {
            return pre;
        }
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    ListNode *reverseList(ListNode *head)
    {
        return reverse(NULL, head);
    }
};