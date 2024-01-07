// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
       double ans=1;
        long absn=abs((long)n);
        while(absn>0)
        {
            if((absn&1)==1) ans *= x;
            absn >>= 1;
            x *= x;
        }
        return n < 0 ?  1/ans : ans;
    }
};