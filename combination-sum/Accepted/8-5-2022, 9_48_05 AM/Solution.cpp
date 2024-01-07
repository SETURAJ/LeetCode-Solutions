// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void find(vector<int>nums,vector<vector<int>>&res,vector<int>&r,int target,int i)
    {
        if(target==0)
        {
            res.push_back(r);
            return;
        }
        while(i<nums.size() && target>=nums[i])
        {
            r.push_back(nums[i]);
            find(nums,res,r,target-nums[i],i);
            i++;
            r.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>r;
        find(candidates,res,r,target,0);
        return res;
    }
};