// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    
    int findmax(int h, vector<int>&hv)
    {
        sort(hv.begin(),hv.end());
        int s=hv.size();
        int maxw=max(hv[0],h-hv[s-1]);
        for(int i=1;i<s;i++)
            maxw=max(maxw,hv[i]-hv[i-1]);
        return maxw;
    }
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int width=findmax(h,horizontalCuts);
        int height=findmax(w,verticalCuts);
        return (int)((long)(width*height)%1000000007);
    }
};