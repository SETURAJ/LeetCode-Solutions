// https://leetcode.com/problems/subsets

class Solution {
      
    void solve(vector<int>num,vector<int>op,vector<vector<int>>&res)
    {
        if(num.size()==0)
        { 
            res.push_back(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(num[0]);
        num.erase(num.begin()+0);
        solve(num,op1,res);
        solve(num,op2,res);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>op={};
        solve(nums,op,res);
        return res;
    }
};