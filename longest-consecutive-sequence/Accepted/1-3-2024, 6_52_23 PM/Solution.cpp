// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int res = 0;
        for(auto n:nums)
        {
            if(s.find(n-1)==s.end())
            {
                int y = n+1;
                while(s.find(y)!=s.end())
                    y+=1;
                res=max(res,y-n);
            }
        }
        return res;
    }
};