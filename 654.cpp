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
    TreeNode *traversal(vector<int> &nums)
    {
        if (nums.empty())
        {
            return NULL;
        }
        int index = 0;
        int maxNum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > maxNum)
            {
                index = i;
                maxNum = nums[i];
            }
        }
        TreeNode *root = new TreeNode(maxNum);
        vector<int> left(nums.begin(), nums.begin() + index);
        vector<int> right(nums.begin() + index + 1, nums.end());
        root->left = traversal(left);
        root->right = traversal(right);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return traversal(nums);
    }
};