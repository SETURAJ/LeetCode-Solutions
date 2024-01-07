// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int col=matrix[0].size();
        int cur_row=0;//first row
        int cur_col=col-1;//last col
        while(cur_row< rows && cur_col>-1)
        {
            if(target==matrix[cur_row][cur_col])
                return true;
            if(target > matrix[cur_row][cur_col])
                cur_row++;
            else
                cur_col--;
        }
        return false;
        
    }
};