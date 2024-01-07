// https://leetcode.com/problems/subsets

class Solution {
public:
    void dfs(int ind,vector<int>&nums ,vector<int>sub,vector<vector<int>>&res)
    {
        if(ind>=nums.size())
        {
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[ind]);
        dfs(ind+1,nums,sub,res);
        
        sub.pop_back();
        dfs(ind+1,nums,sub,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int> sub;
        dfs(0,nums,sub,res);
        return res;
    }
};