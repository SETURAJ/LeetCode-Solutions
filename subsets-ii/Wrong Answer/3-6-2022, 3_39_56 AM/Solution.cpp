// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    
    void solve(vector<int>num,vector<int>op,set<vector<int>>&s)
    {
        if(num.size()==0)
        {
            s.insert(op);
            return;
        }
        vector<int>op1=op;
        vector<int>op2=op;
        op2.push_back(num[0]);
        num.erase(num.begin()+0);
        solve(num,op1,s);
        solve(num,op2,s);
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        set<vector<int>>s;
        vector<int>op={};
        solve(nums,op,s);
        for(auto it=s.begin();it!=s.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};