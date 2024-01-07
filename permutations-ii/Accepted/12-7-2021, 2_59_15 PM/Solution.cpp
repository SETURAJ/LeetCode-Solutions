// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    set<vector<int>>ds;
    void find_per(vector<int> nums,int k,int n,vector<vector<int>>& res)
    {
        if(k==n)
        {
            ds.insert(nums);
        }
        else
        {
            for(int i=k;i<=n;i++)
            {
                swap(nums[k],nums[i]);
                find_per(nums,k+1,n,res);
            }
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>result;
        find_per(nums,0,nums.size()-1,result);
        for(auto it=ds.begin();it!=ds.end();it++)
            result.push_back(*it);
        return result;
    }
};