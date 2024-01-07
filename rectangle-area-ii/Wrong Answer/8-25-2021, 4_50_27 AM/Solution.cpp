// https://leetcode.com/problems/rectangle-area-ii


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rect) {
    long long int prev=0;
    long long int res=0;
    int mod = pow(10, 9)+7;
     if(rect.size()==1)
    {
         res=((long)abs(rect[0][0]-rect[0][2])*(long)abs(rect[0][1]-rect[0][3]))%mod;
        
    }
    for(int i=0;i<rect.size()-1;i++)
    {
        long long int area1=abs(rect[i][0]-rect[i][2])*abs(rect[i][1]-rect[i][3]);
        long long int area2=abs(rect[i+1][0]-rect[i+1][2])*abs(rect[i+1][1]-rect[i+1][3]);
        //x and y coordinates of common area
        long long int x=min(rect[i][2],rect[i+1][2])-max(rect[i][0],rect[i+1][0]);
        long long int y=min(rect[i][3],rect[i+1][3])-max(rect[i][1],rect[i+1][1]);
        long long int c_area=0;
        //common area
        if(x>0 && y>0)
            c_area=x*y;
        res+=(area1+area2-c_area-prev)%mod;
        prev=area2;
    }
    return res%mod;
        
    }
};