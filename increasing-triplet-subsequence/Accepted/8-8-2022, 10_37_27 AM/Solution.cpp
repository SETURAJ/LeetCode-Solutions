// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        vector<int>sub;
        for(auto n:nums)
        {
            if(sub.size()>=3)
                return true;
            if(sub.empty() || sub[sub.size()-1]<n)
                sub.push_back(n);
            else
            {
                auto it=lower_bound(sub.begin(),sub.end(),n);
                *it=n;
            }
        }
        if(sub.size()>=3)
            return true;
        return false;
    }
};