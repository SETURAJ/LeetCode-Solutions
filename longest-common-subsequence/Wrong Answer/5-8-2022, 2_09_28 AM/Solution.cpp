// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length(),l2=text2.length();
        vector<vector<int>>sub(l1+1,vector<int>(l2+1,0));
        for(int i=0;i<l1+1;i++)
        {
            for(int j=0;j<l2+1;j++)
            {
                if(i==0 || j==0)
                    sub[i][j]=0;
                else if(sub[i]==sub[j])
                    sub[i][j]=sub[i-1][j-1]+1;
                else
                {
                    sub[i][j]=max(sub[i-1][j],sub[i][j-1]);
                }
                    
            }
        }
        return sub[l1][l2];
    }
};