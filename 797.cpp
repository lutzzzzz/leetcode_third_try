#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstdlib>
#include<cstring>
#include<set>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void traceback(vector<vector<int>>& graph,int nodeIndex){
        if(nodeIndex==graph.size()-1){
            result.push_back(path);
            return;
        }

        for(int i=0;i<graph[nodeIndex].size();i++){
            path.push_back(graph[nodeIndex][i]);
            traceback(graph,graph[nodeIndex][i]);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        traceback(graph,0);
        return result;
    }
};