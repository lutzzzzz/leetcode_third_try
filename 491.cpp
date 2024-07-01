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
    void trackback(vector<int> &nums, int startIndex)
    {
        if (path.size() > 1)
            result.push_back(path);
        unordered_map<int, bool> mmap;
        for (int i = startIndex; i < nums.size(); i++)
        {
            if (mmap[nums[i]] == true || (!path.empty() && nums[i] < path.back()))
                continue;
            mmap[nums[i]] = true;
            path.push_back(nums[i]);
            trackback(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        trackback(nums, 0);
        return result;
    }
};