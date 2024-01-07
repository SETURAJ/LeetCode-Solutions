// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1;
        int p=abs(n);
        for(int i=0;i<p;i++)
        {
            ans=ans*x;
        }
        if(n>0)
            return ans;
        else
            return 1/ans;
    }
};