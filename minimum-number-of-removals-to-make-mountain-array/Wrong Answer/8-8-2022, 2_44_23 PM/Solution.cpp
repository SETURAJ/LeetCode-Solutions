// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    
    int findlis(vector<int>&nums)
    {
         if(!nums.size())
            return 0;
        vector<int>sub;
        for(auto n:nums)
        {
            if(sub.empty() || sub[sub.size()-1]<n)
                sub.push_back(n);
            else
            {
                auto it=lower_bound(sub.begin(),sub.end(),n);
                *it=n;    
            }
        }
        return sub.size();
    }
    
    int minimumMountainRemovals(vector<int>& nums) {
        int left_lis=findlis(nums);
        reverse(nums.begin(),nums.end());
        int right_lis=findlis(nums);
        int answer=-1;
        answer=max(answer,left_lis+right_lis-1);
        return nums.size()-answer;
    }
};