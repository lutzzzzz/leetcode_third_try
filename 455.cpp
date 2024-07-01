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
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int IndexS = s.size() - 1;
        int IndexG = g.size() - 1;
        while (IndexG >= 0)
        {
            if (g[IndexG] <= s[IndexS])
            {
                result++;
                IndexG--;
                IndexS--;
            }
            else
            {
                IndexG--;
            }
        }
        return result;
    }
};