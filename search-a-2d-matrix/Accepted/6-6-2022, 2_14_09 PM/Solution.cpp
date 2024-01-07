// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a=-1,n=matrix.size();
        for(int i=0;i<n-1;i++)
        {
            if(target==matrix[i][0] || target==matrix[i+1][0])
                return true;
            if(target>matrix[i][0] && target<matrix[i+1][0])
                a=i;
        }
        if(a==-1)
            a=n-1;
        int m=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            if(target==matrix[a][i])
                return true;
        }
        return false;
    }
};