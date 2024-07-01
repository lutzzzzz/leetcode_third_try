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
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
                return false;
        }
        return true;
    }

    void backtrack(string s, int startIndex)
    {
        if (startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < s.size(); i++)
        {
            string substr(s.begin() + startIndex, s.begin() + i + 1);
            if (isPalindrome(substr))
            {
                path.push_back(substr);
                backtrack(s, i + 1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        backtrack(s, 0);
        return result;
    }
};