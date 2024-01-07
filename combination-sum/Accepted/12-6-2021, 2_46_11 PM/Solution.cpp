// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void findanswer(int index,int target,vector<int>&ds,vector<vector<int>>&res,vector<int>& nums)
    {
        if(index==nums.size())
        {
            if(target==0)
            {
                res.push_back(ds);
            }
        return ;
        }
        if(nums[index]<=target)
        {
            ds.push_back(nums[index]);
            findanswer(index,target-nums[index],ds,res,nums);
            ds.pop_back();
        }
        findanswer(index+1,target,ds,res,nums);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        if(candidates.size()==0)
            return res;
        vector<int>ds;
        findanswer(0,target,ds,res,candidates);
        return res;
    }
};