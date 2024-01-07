// https://leetcode.com/problems/continuous-subarray-sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixsum=0;
        map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            prefixsum+=nums[i];
            int rem=prefixsum%k;
            if(mp.count(rem))
            {
                int len=i-mp[rem];
                if(len>1)
                    return true;
                else
                    continue;
            }
            mp[rem]=i;
        }
        return false;
    }
};