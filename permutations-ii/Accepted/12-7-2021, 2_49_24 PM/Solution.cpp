// https://leetcode.com/problems/permutations-ii

class Solution {
public:
    void find_per(vector<int> nums,int k,int n,vector<vector<int>>& res)
    {
        if(k==n)
        {
            res.push_back(nums);
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
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};