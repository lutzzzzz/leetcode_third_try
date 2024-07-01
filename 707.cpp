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

class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList()
    {
        length = 0;
        dummyHead = new ListNode(0);
    }

    int get(int index)
    {
        if (index > length - 1 || index < 0)
        {
            return -1;
        }

        ListNode *cur = dummyHead;
        for (int i = 0; i <= index; i++)
        {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *node = new ListNode(val);
        ListNode *tmp = dummyHead->next;
        dummyHead->next = node;
        if (tmp != NULL)
        {
            node->next = tmp;
        }
        length++;
    }

    void addAtTail(int val)
    {
        ListNode *node = new ListNode(val);
        ListNode *cur = dummyHead;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = node;
        length++;
    }
    
    void addAtIndex(int index, int val)
    {
        if (index > length || index < 0)
        {
            return;
        }

        ListNode *node = new ListNode(val);
        ListNode *cur = dummyHead;

        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = node;
        node->next = tmp;
        length++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= length || index < 0)
        {
            return;
        }

        ListNode *cur = dummyHead;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }

        ListNode *tmp = cur->next;
        if (tmp != NULL)
        {
            cur->next = tmp->next;
            delete tmp;
            length--;
        }
    }

private:
    int length;
    ListNode *dummyHead;
};