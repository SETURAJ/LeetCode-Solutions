// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a=0,n=matrix.size();
        for(int i=0;i<n-1;i++)
        {
            if(target==matrix[i][0] || target==matrix[i+1][0])
                return true;
            if(target>matrix[i][0] && target<matrix[i+1][0])
                a=i;
        }
        if(a==0)
            a=n-1;
        for(int i=0;i<matrix[0].size();i++)
        {
            if(target==matrix[a][i])
                return true;
        }
        return false;
    }
};