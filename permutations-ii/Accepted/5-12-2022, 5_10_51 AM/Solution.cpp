// https://leetcode.com/problems/permutations-ii

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
            if(k!=i && nums[k]==nums[i])
                continue;
            swap(nums[k],nums[i]);
            find_sol(nums,k+1,n,res);
            
        }
      
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
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