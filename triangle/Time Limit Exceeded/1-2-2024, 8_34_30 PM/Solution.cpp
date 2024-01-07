// https://leetcode.com/problems/triangle

class Solution {
public:
    
    int minpath(int i,int j,vector<vector<int>>&triangle)
    {
        if(i==triangle.size())
            return 0;
        return triangle[i][j] + min(minpath(i+1,j,triangle),minpath(i+1,j+1,triangle));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        return minpath(0,0,triangle);
    }
};