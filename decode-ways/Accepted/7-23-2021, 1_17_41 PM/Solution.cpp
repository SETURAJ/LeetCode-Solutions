// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        int dp[n];
        if(s[0]=='0')
            return 0;
        dp[0]=1;
        if(n==1)
            return 1;
        int q=(s[0]-'0')*10+(s[1]-'0');
        if(q<=26 && q>=1 && s[1]!='0')
            dp[1]=2*dp[0];
        else if(s[1]=='0' && q>=1 && q<=26 )
            dp[1]=dp[0];
        else if(s[1]!='0')
            dp[1]=dp[0];
        else
            dp[1]=0;
        if(n==2)
            return dp[1];
        for(int i=2;i<n;i++)
        {
            int p=(s[i-1]-'0')*10+(s[i]-'0');
            
            if(s[i]=='0' && p>=1 && p<=26)
                dp[i]=dp[i-2];
            else if(s[i]=='0' &&(p<1 || p>26))
                dp[i]=0;
            else if(p<=26 && p>=1 && s[i-1]!='0')
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
                dp[i]=dp[i-1];
        }
        
        return dp[n-1];
    }
};