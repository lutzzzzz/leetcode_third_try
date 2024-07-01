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
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
            return 0;
        int fast = 0;
        int slow = 0;

        for (; fast < nums.size() - 1; fast++)
        {
            if (nums[slow] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};