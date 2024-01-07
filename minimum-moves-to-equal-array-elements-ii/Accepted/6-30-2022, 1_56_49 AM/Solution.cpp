// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==1)
            return 0;
        int med=0;
        if(n%2==1)
        {
            med=nums[n/2];
        }
        else
        {
            med=(nums[n/2]+nums[n/2-1])/2;
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=abs(med-nums[i]);
        }
        return res;
    }
};