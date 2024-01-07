// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int maxp=1,minp=1;
        int ans=INT_MIN;
        for(int n:nums)
        {
            if(n<0)
                swap(maxp,minp);
            maxp=max(maxp*n,n);
            minp=min(minp*n,n);
            ans=max(ans,maxp);
        }
        return ans;
    }
};