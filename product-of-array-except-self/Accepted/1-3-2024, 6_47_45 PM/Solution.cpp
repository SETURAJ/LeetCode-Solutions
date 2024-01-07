// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
       /* vector<int> res(n);
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=1;
        suff[n-1]=1;
        for(int i=1;i<n;i++)
            pref[i] = pref[i-1] * nums[i-1];
        for(int i=n-2;i>=0;i--)
            suff[i] = suff[i+1] * nums[i+1];
        for(int i=0;i<n;i++)
            res[i] = pref[i]*suff[i];
        */
        
        vector<int>res(n,1);
        int curr=1;
        for(int i=0;i<n;i++)
        {
            res[i]*=curr;
            curr*=nums[i];
        }
        curr=1;
        for(int i=n-1;i>=0;i--)
        {
            res[i]*=curr;
            curr*=nums[i];
        }
        return res;
    }
};