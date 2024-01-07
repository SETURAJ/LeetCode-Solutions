// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1 && k%2==1)
            return -1;
        int res=INT_MIN;
        for(int i=0;i<min(n,k-1);i++)
            res=max(res,nums[i]);
        if(k<n)
            res=max(res,nums[k]);
        return res;
    }
};