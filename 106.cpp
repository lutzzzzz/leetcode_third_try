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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.empty())
        {
            return NULL;
        }

        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);

        int index = 0;
        for (; index < inorder.size(); index++)
        {
            if (inorder[index] == rootValue)
                break;
        }

        vector<int> inorder_left(inorder.begin(), inorder.begin() + index);
        vector<int> inorder_right(inorder.begin() + index + 1, inorder.end());
        vector<int> postorder_left(postorder.begin(), postorder.begin() + index);
        vector<int> postorder_right(postorder.begin() + index, postorder.end() - 1);

        root->left = traversal(inorder_left, postorder_left);
        root->right = traversal(inorder_right, postorder_right);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return traversal(inorder, postorder);
    }
};