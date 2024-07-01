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
    int traversal(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int sum = 0;
        if (node->left && !node->left->left && !node->left->right)
        {
            sum += node->left->val;
        }
        sum += traversal(node->left);
        sum += traversal(node->right);
        return sum;
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return traversal(root);
    }
};