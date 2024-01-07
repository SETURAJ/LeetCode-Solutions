// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    
    void dfs(int ind,int n,set<vector<int>>&s,vector<int>ds,vector<int>nums)
    {
        if(ind>=n)
        {
            sort(ds.begin(),ds.end());
            s.insert(ds);
            return;
        }
        
        ds.push_back(nums[ind]);
        dfs(ind+1,n,s,ds,nums);
        
        ds.pop_back();
        dfs(ind+1,n,s,ds,nums);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        
        vector<vector<int>>res;
        vector<int>ds;
        int n = nums.size();
        dfs(0,n,s,ds,nums);
        for(auto&v :s)
            res.push_back(v);
        return res;
    }
};