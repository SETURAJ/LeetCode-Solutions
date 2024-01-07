// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void dfs(int ind,vector<int>&nums, int total,int target, vector<int>ds,vector<vector<int>>&res)
    {
        if(total==target)
        {
            res.push_back(ds);
            return;
        }
        if(ind >= nums.size() || total>target)
            return;
        
        ds.push_back(nums[ind]);
        dfs(ind,nums,total+nums[ind],target,ds,res);
        
        ds.pop_back();
        dfs(ind+1,nums,total,target,ds,res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        dfs(0,candidates,0,target,ds,res);
        return res;
    }
};