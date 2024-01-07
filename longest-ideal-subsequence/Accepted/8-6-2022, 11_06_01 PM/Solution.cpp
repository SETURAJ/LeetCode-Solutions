// https://leetcode.com/problems/longest-ideal-subsequence

class Solution
{
public:
    
    void find(string s,int n,int k,vector<int>&dp)
    {
        for (int i = 0; i < n; i++)
        {
            int b = s[i] - 'a', 
            trace = dp[b];
            for (int ch= 0; ch< 26; ch++)
            {
                if (abs(ch - b) <= k)
                {
                    trace = max(trace, dp[ch] + 1);
                }
            }
            dp[b] = trace;
        }
    }
    
    int longestIdealString(string s, int k)
    {
        int n = s.size();
        vector<int>dp(26);
        find(s,n,k,dp);
        
        return *max_element(begin(dp), end(dp));
    }
};