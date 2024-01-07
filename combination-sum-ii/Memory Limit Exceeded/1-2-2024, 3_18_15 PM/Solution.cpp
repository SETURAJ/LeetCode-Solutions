// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    
    void solve(int ind,int total,int target,vector<int>&nums,vector<int>ds,set<vector<int>>&s)
    {
        if(total==target)
        {
            sort(ds.begin(),ds.end());
            s.insert(ds);
            return;
        }
        if(ind>=nums.size() || total > target)
            return;
        ds.push_back(nums[ind]);
        solve(ind+1,total+nums[ind],target,nums,ds,s);
        
        ds.pop_back();
        solve(ind+1,total,target,nums,ds,s);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        set<vector<int>>s;
        vector<vector<int>>res;
        
        solve(0,0,target,candidates,ds,s);
        for(auto &v:s)
            res.push_back(v);
        return res;
    }
};