// https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1=abs(ax2-ax1)*abs(ay2-ay1);
        int a2=abs(bx2-bx1)*abs(by2-by1);
        int x=min(bx2,ax2)-max(bx1,ax1);
        int y=min(by2,ay2)-max(by1,ay1);
        int a3=(x>0 && y>0) ? x*y:0;
        return a1+a2-a3;
    }
};