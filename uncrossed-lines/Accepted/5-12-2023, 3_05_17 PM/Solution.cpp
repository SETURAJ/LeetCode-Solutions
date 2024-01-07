// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:
    /*
    int func(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp)
    {
        if(i==nums1.size() || j==nums2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int count=0;
        if(nums1[i]==nums2[j])
            count=1+func(i+1,j+1,nums1,nums2,dp);
        else
            count+=max(func(i+1,j,nums1,nums2,dp),func(i,j+1,nums1,nums2,dp));
        return dp[i][j]=count;
    }
    */
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0 )
                    dp[i][j]=0;
                else if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};