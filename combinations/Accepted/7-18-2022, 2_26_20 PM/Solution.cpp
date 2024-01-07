// https://leetcode.com/problems/combinations

class Solution {
public:
    
    void findcomb(vector<vector<int>>&res,vector<int>&temp,int n,int k,int start, int count)
    {
        if(count==k)
        {
            res.push_back(temp);
            return;
        }
        for(int i=start;i<n;i++)
        {
            temp.push_back(i+1);
            findcomb(res,temp,n,k,i+1,count+1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        if(n<k)
            return res;
        vector<int>temp(0,k);
        findcomb(res,temp,n,k,0,0);
        return res;
    }
};