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

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        int index = nums.size() - 1;
        int left = 0;
        int right = nums.size() - 1;

        while (right >= left)
        {
            int sqrt_right = nums[right] * nums[right];
            int sqrt_left = nums[left] * nums[left];

            if (sqrt_right >= sqrt_left)
            {
                result[index] = sqrt_right;
                index--;
                right--;
            }
            else
            {
                result[index] = sqrt_left;
                index--;
                left++;
            }
        }

        return result;
    }
};