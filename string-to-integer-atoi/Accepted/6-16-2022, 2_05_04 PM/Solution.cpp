// https://leetcode.com/problems/string-to-integer-atoi


class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        bool positive=1;
        int i=0,n=s.length(),x=0;
        while(i<n && s[i]==' ') i++;
        if(i<n)
        {
            if(s[i]=='-')
            {
                positive=0;
                i++;
            }
            else if(s[i]=='+')
                i++;
            while(i<n && s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+s[i]-'0';
                x = positive ? min((long)INT_MAX,ans) : abs(max((long)INT_MIN,0-ans));
                if(x!=ans)
                {
                    ans=x;
                    break;
                }
                i++;
            }
        }
        return positive? ans:-ans;
    }
};