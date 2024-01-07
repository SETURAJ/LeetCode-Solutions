// https://leetcode.com/problems/longest-ideal-subsequence

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        vector<int>dp(26,0);
        dp[s[n-1]-'a']=1;
        for(int i=n-2;i>=0;i--)
        {
            int l=max(0,(s[i]-'a')-k);
            int r=min(25,(s[i]-'a')+k);
            int res=0;
            for(int i=l;i<=r;i++)
                res=max(res,dp[i]);
            dp[s[i]-'a']=max(res+1,dp[s[i]-'a']);
        }
        int ans=0;
        for(int i=0;i<26;i++)
            ans=max(ans,dp[i]);
        return ans;
    }
};