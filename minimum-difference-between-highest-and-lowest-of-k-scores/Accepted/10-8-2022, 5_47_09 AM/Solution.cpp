// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        int res=INT_MAX;
        for(int i=0;i<=nums.size()-k;i++)
        {
            res=min(res,nums[i]-nums[i+k-1]);
        }
        return res;
    }
};