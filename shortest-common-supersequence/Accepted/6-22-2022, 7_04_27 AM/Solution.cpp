// https://leetcode.com/problems/shortest-common-supersequence

class Solution {
public:
    
    int lcs(string text1,string text2,vector<vector<int>>&dp)
    {
        int l1=text1.length(),l2=text2.length();
        for(int i=0;i<l1+1;i++)
        {
            for(int j=0;j<l2+1;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[l1][l2];
    }    
    
    string shortestCommonSupersequence(string str1, string str2) {
        if(str1==str2)
            return str1;
        int l1=str1.length(),l2=str2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        int len=lcs(str1,str2,dp);
        int i=l1,j=l2;
        string ans="";
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=str1[i-1];
                i--;
            }
            else
            {
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0)
        {
            ans+=str1[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};