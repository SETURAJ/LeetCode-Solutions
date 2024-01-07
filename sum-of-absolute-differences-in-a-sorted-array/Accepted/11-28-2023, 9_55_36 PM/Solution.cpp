// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixsum(n);
        int total=0;
        for(int i=0;i<n;i++)
            total+=nums[i];
        int left=0;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            int right = total - left - nums[i];
            
            int leftcount = i;
            int rightcount = n-i-1;
            int lt= nums[i]*leftcount - left;
            int rt= right - nums[i]*rightcount;
            res.push_back(lt+rt);
            left+=nums[i];
        }
        return res;
    }
};