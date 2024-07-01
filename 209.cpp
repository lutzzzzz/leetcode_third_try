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
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int result = INT32_MAX;
        int sum = 0;
        bool flag = false;

        for (; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                sum -= nums[left];
                left++;
                flag = true;
            }
            if (flag)
            {
                result = min(result, right - left + 2);
                flag = false;
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};