// https://leetcode.com/problems/matrix-diagonal-sum

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=mat[i][i];
            res+=mat[i][n-i-1];
        }
        if(n%2==1)
            res-=mat[(n-1)/2][(n-1)/2];
        return res;
    }
};