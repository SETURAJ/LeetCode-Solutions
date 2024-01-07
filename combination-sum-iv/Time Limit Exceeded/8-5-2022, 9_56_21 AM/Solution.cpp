// https://leetcode.com/problems/combination-sum-iv

class Solution {
public:
    int res=0;
   
    void find(vector<int>nums,int target)
    {
        if(target==0)
        {
            res+=1;
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(target<nums[i])
                break;
            find(nums,target-nums[i]);
        }
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        find(nums,target);
        return res;
        
    }
};