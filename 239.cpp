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

class DecreaseQueue
{
public:
    DecreaseQueue(){};
    void push_back(int num)
    {
        while (!que.empty() && que.back() < num)
        {
            que.pop_back();
        }
        que.push_back(num);
    };
    void pop_front(int num)
    {
        if (!que.empty() && num == que.front())
        {
            que.pop_front();
        }
    };
    int top()
    {
        return que.front();
    };

private:
    deque<int> que;
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        DecreaseQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++)
        {
            que.push_back(nums[i]);
        }
        result.push_back(que.top());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop_front(nums[i - k]);
            que.push_back(nums[i]);
            result.push_back(que.top());
        }
        return result;
    }
};