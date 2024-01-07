// https://leetcode.com/problems/non-decreasing-subsequences

class Solution {
public:
    
    void solve(int ind,vector<int>&ds,set<vector<int>>&st,vector<int>&nums)
    {
        if(ds.size()>=2)
            st.insert(ds);
        for(int i=ind;i<nums.size();i++)
        {
            if(ds.size()==0 || ds[ds.size()-1]<=nums[i])
            {
                ds.push_back(nums[i]);
                solve(i+1,ds,st,nums);
                ds.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ds;
        set<vector<int>>st;
        solve(0,ds,st,nums);
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};