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
    void backtrack(vector<int> &candidates, int target, int sum, int startIndex)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        else if (sum > target)
        {
            return;
        }
        else
        {
            for (int i = startIndex; i < candidates.size(); i++)
            {
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtrack(candidates, target, sum, i);
                path.pop_back();
                sum -= candidates[i];
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates, target, 0, 0);
        return result;
    }
};