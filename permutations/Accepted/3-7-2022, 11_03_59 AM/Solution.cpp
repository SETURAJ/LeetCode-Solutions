// https://leetcode.com/problems/permutations

class Solution {
public:
    void find_sol(vector<int> nums,int k,int n,vector<vector<int>>& res)
    {
        
        if(k==n){
            res.push_back(nums);
        }
        else
        {
            for(int i=k;i<=n;i++)
            {
                swap(nums[k],nums[i]);
                find_sol(nums,k+1,n,res);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        if(nums.size()==0)
            return result;
        if(nums.size()==1)
        {
            result.push_back(nums);
            return result;
        }
        find_sol(nums,0,nums.size()-1,result);
        return result;
    }
};