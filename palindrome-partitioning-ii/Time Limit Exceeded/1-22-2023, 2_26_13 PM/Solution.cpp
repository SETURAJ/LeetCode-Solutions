// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:

    bool ispal(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }

    int solve(string& s,int i,int j, vector<int>&dp)
    {
        if(i>=j || ispal(s,i,j))
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            if(ispal(s,i,k))
            {
                int temp=solve(s,k+1,j,dp)+1;
                ans=min(ans,temp);
            }
        }
        return dp[i]=ans;
    }

    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(s,0,n-1,dp);
    }
};