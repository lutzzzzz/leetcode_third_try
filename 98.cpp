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
    vector<int> vec;
    void traversal(TreeNode *node)
    {
        if (node == NULL)
            return;
        traversal(node->left);
        vec.push_back(node->val);
        traversal(node->right);
    }
    bool isValidBST(TreeNode *root)
    {
        traversal(root);
        if (vec.empty() || vec.size() == 1)
            return true;
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] >= vec[i + 1])
                return false;
        }
        return true;
    }
};