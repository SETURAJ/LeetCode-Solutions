// https://leetcode.com/problems/minimum-increment-to-make-array-unique

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0,need=0;
        for(int n:nums)
        {
            res+=max(need-n,0);
            need=max(n,need)+1;
        }
        return res;
    }
};