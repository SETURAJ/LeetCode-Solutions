// https://leetcode.com/problems/rotate-function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0,curr=0,prev=0,f0=0,res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            f0+=i*nums[i];
        }
        res=f0;
        prev=f0;
        for(int i=1;i<n;i++)
        {
            curr=prev+sum-n*nums[n-i];
            prev=curr;
            res=max(res,curr);
        }
        return res;
    }
};