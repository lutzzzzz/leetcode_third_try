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

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if(root==NULL) return NULL;
        queue<Node *> que;
        que.push(root);

        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                if (i == size - 1)
                {
                    Node *node = que.front();
                    que.pop();
                    node->next = NULL;
                    if (node->left)
                        que.push(node->left);
                    if (node->right)
                        que.push(node->right);
                }
                else
                {
                    Node *cur = que.front();
                    que.pop();
                    Node *nxt = que.front();
                    cur->next = nxt;
                    if (cur->left)
                        que.push(cur->left);

                    if (cur->right)
                        que.push(cur->right);
                }
            }
        }
        return root;
    }
};