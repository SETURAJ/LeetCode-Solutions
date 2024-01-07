// https://leetcode.com/problems/transpose-matrix

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>res(col,vector<int>(rows,0));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
    
};