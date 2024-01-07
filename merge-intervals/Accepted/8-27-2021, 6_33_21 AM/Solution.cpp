// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        for(const auto &inter:intervals)
        {
            if(merged.empty()||merged.back()[1]<inter[0]) 
                merged.push_back(inter);
            else
            {
                merged.back()[1]=max(merged.back()[1],inter[1]);
            }
        }
        return merged;
    }
};