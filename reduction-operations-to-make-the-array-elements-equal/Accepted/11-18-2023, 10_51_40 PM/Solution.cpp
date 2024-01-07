// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int cnt = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
                cnt++;
            res+=cnt;
        }
        return res;
    }
};