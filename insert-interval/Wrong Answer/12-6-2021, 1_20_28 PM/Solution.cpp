// https://leetcode.com/problems/insert-interval

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
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>result;
        int pos=0;
        if(intervals.size()==0)
            intervals.push_back(newInterval);
        else
        for(const auto& inter:intervals)
        {
            if(inter[0]>newInterval[0])
                intervals.insert(intervals.begin()+pos,newInterval);
            else
                pos++;
        }
        result=merge(intervals);
        return result;
    }
};