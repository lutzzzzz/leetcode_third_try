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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pre = 0;
    void traversal(TreeNode *cur)
    {
        if (cur == NULL)
            return;
        traversal(cur->right);
        cur->val += pre;
        pre = cur->val;
        traversal(cur->left);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        traversal(root);
        return root;
    }
};