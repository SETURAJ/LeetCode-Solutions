// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>left_pro(n);
        vector<int>right_pro(n);
        left_pro[0]=1;
        for(int i=1;i<n;i++)
            left_pro[i]=left_pro[i-1]*nums[i-1];
        right_pro[n-1]=1;
        for(int j=n-2;j>=0;j--)
            right_pro[j]=right_pro[j+1]*nums[j+1];
        for(int i=0;i<n;i++)
            ans[i]=left_pro[i]*right_pro[i];
        return ans;
    }
};