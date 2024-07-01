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
    void backtrack(int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++)
        {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtrack(n, k, 1);
        return result;
    }
};