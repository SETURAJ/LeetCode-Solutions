// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string>res;
        for(int i=0;i<n;i++)
        {
            int start=nums[i];
            while(i!=(n-1) && nums[i]==nums[i+1]-1)
                i++;
            int last=nums[i];
            if(start==last)
                res.push_back(to_string(start));
            else
                res.push_back(to_string(start) +"->"+ to_string(last));
        }
        return res;
    }
};