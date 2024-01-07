// https://leetcode.com/problems/rectangle-area-ii

#define t 1000000007
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rect) {
         int prev=0;
    int res=0;
    if(rect.size()==1)
    {
        int res=(abs(rect[0][0]-rect[0][2])*abs(rect[0][1]-rect[0][3]))%t;
        
    }
    else
    {
    for(int i=0;i<rect.size()-1;i++)
    {
        int area1=abs(rect[i][0]-rect[i][2])*abs(rect[i][1]-rect[i][3]);
        int area2=abs(rect[i+1][0]-rect[i+1][2])*abs(rect[i+1][1]-rect[i+1][3]);
        //x and y coordinates of common area
        int x=min(rect[i][2],rect[i+1][2])-max(rect[i][0],rect[i+1][0]);
        int y=min(rect[i][3],rect[i+1][3])-max(rect[i][1],rect[i+1][1]);
        int c_area=0;
        //common area
        if(x>0 && y>0)
            c_area=x*y;
        res+=area1+area2-c_area-prev;
        prev=area2;
    }
    }
    return res%t;
        
    }
};