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
    void trackback(int k, int n, int sum, int startIndex)
    {
        if (path.size() == k)
        {
            if (sum == n)
                result.push_back(path);
            return;
        }

        for (int i = startIndex; i <= 9; i++)
        {
            if ((i + sum) > n)
                continue;
            path.push_back(i);
            sum += i;
            trackback(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        trackback(k, n, 0, 1);
        return result;
    }
};