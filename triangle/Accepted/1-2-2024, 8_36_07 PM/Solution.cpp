// https://leetcode.com/problems/triangle

class Solution {
public:
    
    int minpath(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&memo)
    {
        if(i==triangle.size())
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        return memo[i][j]= triangle[i][j] + min(minpath(i+1,j,triangle,memo),minpath(i+1,j+1,triangle,memo));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>memo(m,vector<int>(m,-1));
        return minpath(0,0,triangle,memo);
    }
};