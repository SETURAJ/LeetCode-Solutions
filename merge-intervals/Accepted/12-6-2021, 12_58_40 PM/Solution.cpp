// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
        for(const auto &inter:intervals)
        {
            if(result.size()==0||result.back()[1]<inter[0])
                result.push_back(inter);
            else
                result.back()[1]=max(result.back()[1],inter[1]);
                
        }
        return result;
    }
};