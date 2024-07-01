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

class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        while (!stIn.empty())
        {
            stOut.push(stIn.top());
            stIn.pop();
        }
        int rtn = stOut.top();
        stOut.pop();
        while (!stOut.empty())
        {
            stIn.push(stOut.top());
            stOut.pop();
        }
        return rtn;
    }

    int peek()
    {
        while (!stIn.empty())
        {
            stOut.push(stIn.top());
            stIn.pop();
        }
        int rtn = stOut.top();
        while (!stOut.empty())
        {
            stIn.push(stOut.top());
            stOut.pop();
        }
        return rtn;
    }

    bool empty()
    {
        return stIn.empty();
    }

private:
    stack<int> stIn;
    stack<int> stOut;
};