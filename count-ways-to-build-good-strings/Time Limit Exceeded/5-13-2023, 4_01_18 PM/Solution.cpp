// https://leetcode.com/problems/count-ways-to-build-good-strings

class Solution {
public:

    int m=1e9+7;

    int func(int n,int zero,int one)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        int a=0,b=0;
        if(n>=zero)
            a=func(n-zero,zero,one);
        if(n>=one)
            b=func(n-one,zero,one);
        return (a+b)%m;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int res=0;
        for(int i=low;i<=high;i++)
        {
            res+=func(i,zero,one);
        }
        return res;
    }
};