// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++)
        {
            int j=matrix[0].size()-1;
            int count=0;
            while(count<=j)
            {
                swap(matrix[i][count],matrix[i][j]);
                count++;
                j--;
            }
        }
    }
};