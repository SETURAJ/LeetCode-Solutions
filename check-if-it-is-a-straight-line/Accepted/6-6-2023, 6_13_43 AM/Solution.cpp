// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution {
public:

    int getydiff(vector<int>& a, vector<int>& b) 
    {
        return a[1] - b[1];
    }
    
    int getxdiff(vector<int>& a, vector<int>& b) 
    {
        return a[0] - b[0];
    }
    

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<2)
            return false;
        if(coordinates.size()==2)
            return true;
        int ydiff=getydiff(coordinates[1],coordinates[0]);
        int xdiff=getxdiff(coordinates[1],coordinates[0]);

        for(int i=2;i<coordinates.size();i++)
        {
            if(ydiff * getxdiff(coordinates[i],coordinates[0])!= xdiff * getydiff(coordinates[i],coordinates[0]))
                return false;
        }
        return true;
    }
};