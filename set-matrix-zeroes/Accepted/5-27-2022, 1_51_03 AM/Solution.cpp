// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool rowzero=false,colzero=false;
        int rows=mat.size();
        int cols=mat[0].size();
        for(int i=0;i<cols;i++)
        {
            if(mat[0][i]==0)
            {
                rowzero=true;
                break;
            }
        }
        for(int i=0;i<rows;i++)
        {
            if(mat[i][0]==0)
            {
                colzero=true;
                break;
            }
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                {
                    mat[i][j]=0;
                }
            }
        }
        if(rowzero)
        {
            for(int i=0;i<cols;i++)
                mat[0][i]=0;
        }
        if(colzero)
        {
            for(int i=0;i<rows;i++)
                mat[i][0]=0;
        }
        
    }
};