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

    void traceback(vector<int> &candidates, int target, int sum, vector<bool> &used, int startIndex)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        if (sum > target)
        {
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (i > 0 && candidates[i - 1] == candidates[i] && used[i - 1] == false)
            {
                continue;
            }
            sum += candidates[i];
            used[i] = true;
            path.push_back(candidates[i]);
            traceback(candidates, target, sum, used, i + 1);
            sum -= candidates[i];
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        traceback(candidates, target, 0, used, 0);
        return result;
    }
};