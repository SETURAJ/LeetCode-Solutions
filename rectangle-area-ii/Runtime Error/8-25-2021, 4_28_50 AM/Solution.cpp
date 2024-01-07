// https://leetcode.com/problems/rectangle-area-ii


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rect) {
    unsigned long long prev=0;
    unsigned long long res=0;
    int mod = pow(10, 9)+7;
    if(rect.size()==1)
    {
         res=(abs(rect[0][0]-rect[0][2])*abs(rect[0][1]-rect[0][3]))%mod;
        
    }
    else
    {
    for(int i=0;i<rect.size()-1;i++)
    {
        unsigned long long area1=abs(rect[i][0]-rect[i][2])*abs(rect[i][1]-rect[i][3]);
        unsigned long long area2=abs(rect[i+1][0]-rect[i+1][2])*abs(rect[i+1][1]-rect[i+1][3]);
        //x and y coordinates of common area
        unsigned long long x=min(rect[i][2],rect[i+1][2])-max(rect[i][0],rect[i+1][0]);
        unsigned long long y=min(rect[i][3],rect[i+1][3])-max(rect[i][1],rect[i+1][1]);
        unsigned long long c_area=0;
        //common area
        if(x>0 && y>0)
            c_area=x*y;
        res+=(area1+area2-c_area-prev)%mod;
        prev=area2;
    }
    }
    return res%mod;
        
    }
};