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
    vector<vector<int>> result;
    vector<int> path;
    void trackback(vector<int> &nums, int startIndex, vector<bool> &used)
    {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            trackback(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        trackback(nums, 0, used);
        return result;
    }
};