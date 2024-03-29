// https://leetcode.com/problems/permutations

class Solution {
public:
    
    void solve(vector<vector<int>>&res,vector<int>nums,int k)
    {
        if(k==nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=k;i<nums.size();i++)
        {
            swap(nums[i],nums[k]);
            solve(res,nums,k+1);
            swap(nums[i],nums[k]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(res,nums,0);
        return res;
    }
};