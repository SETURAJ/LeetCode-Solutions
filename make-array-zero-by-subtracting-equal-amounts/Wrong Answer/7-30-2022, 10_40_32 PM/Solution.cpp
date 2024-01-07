// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int nz=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                nz++;
        }
        if(nz==0)
            return 0;
        return nz-1;
    }
};