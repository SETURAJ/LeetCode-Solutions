// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())
            return 0;
        vector<int>sub;
        for(auto n:nums)
        {
            if(sub.empty()||sub[sub.size()-1]<n)
                sub.push_back(n);
            else
            {
                auto it=lower_bound(sub.begin(),sub.end(),n);
                *it=n;
            }
        }
        return sub.size();
    }
};