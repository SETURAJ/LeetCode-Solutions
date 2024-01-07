// https://leetcode.com/problems/subsets

class Solution {
    void solve(int ind,vector<int>&nums,vector<int>ds,vector<vector<int>>&res)
    {
        res.push_back(ds);
        for(int i=ind;i<nums.size();i++)
        {
            ds.push_back(nums[i]);
            solve(i+1,nums,ds,res);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ds;
        solve(0,nums,ds,res);
        return res;
    }
};