// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>s(nums.begin(),nums.end());
        for(auto num:nums)
        {
            if(s.find(num-1)==s.end())
            {
                int y=num+1;
                while(s.find(y)!=s.end())
                    y+=1;
                ans=max(ans,y-num);
            }
        }
        return ans;
    }
};