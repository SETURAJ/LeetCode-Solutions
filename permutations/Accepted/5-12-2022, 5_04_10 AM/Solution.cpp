// https://leetcode.com/problems/permutations

class Solution {
public:
    void find_sol(vector<int> nums,int k,int n,vector<vector<int>>& res)
    {
        if(k==n-1)
        {
            res.push_back(nums);
            return;
        }
        for(int i=k;i<n;i++)
        {
            swap(nums[k],nums[i]);
            find_sol(nums,k+1,n,res);
            
        }
      
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        if(nums.size()==0)
            return res;
        if(nums.size()==1)
        {
            res.push_back(nums);
            return res;
        }
        int n=nums.size();
        find_sol(nums,0,n,res);
        return res;
    }
};