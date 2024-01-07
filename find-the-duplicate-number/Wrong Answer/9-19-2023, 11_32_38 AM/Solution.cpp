// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int sum = (n*(n-1))/2;
        int arrsum=0;
        for(int i=0;i<n;i++)
            arrsum += nums[i];
        return arrsum-sum;
    };
    
};