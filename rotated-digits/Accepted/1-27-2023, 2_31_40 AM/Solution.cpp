// https://leetcode.com/problems/rotated-digits

class Solution {
public:
    int rotatedDigits(int n) {
        int res=0;
        for(int i=1;i<=n;i++)
        {
            bool flag1=true,flag2=false;
            int a=i;
            while(a)
            {
                int x=a%10;
                a/=10;
                if(x==3 || x==4 || x==7)
                {
                    flag1=false;
                    break;
                }
                else if(x==2 || x==5 || x==6 || x==9)
                    flag2=true;
            }
            if(flag1 && flag2)
                res++;
        }
        return res;
    }
};