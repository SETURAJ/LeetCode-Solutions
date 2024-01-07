// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size())
            return false;
        int low=0;
        int hi=(matrix.size()*matrix[0].size())-1;
        while(low<=hi)
        {
            int mid=low+(hi-low)/2;
            if(matrix[mid/matrix.size()][mid%matrix.size()]==target)
                return true;
            if(matrix[mid/matrix.size()][mid%matrix.size()]<target)
                low=mid+1;
            else
                hi=mid-1;
        }
        return false;
        
    }
};