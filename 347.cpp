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
    class mycomparison
    {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> rhs)
        {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        for (auto it : map)
        {
            pri_que.push(it);
            if (pri_que.size() > k)
            {
                pri_que.pop();
            }
        }

        vector<int> result;
        for (int i = k - 1; i >= 0; i--)
        {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return result;
    }
};