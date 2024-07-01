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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            auto it = map.find(target-nums[i]);
            if(it!=map.end()){
                return {it->second,i};
            }
            else{
                map[nums[i]]=i;
            }
        }
        return {};
    }
};