// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return true;
        int count=0;
        for(int i=0;i<=n-2;i++)
        {
            if(count>=2)
                return false;
            if(nums[i]>nums[i+1])
                count++;
            
        }
        if(count>=2)
            return false;
        return true;
    }
};