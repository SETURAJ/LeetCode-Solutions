// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
       vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        int numz,numo;
        for(auto &s:strs)
        {
            numz=0,numo=0;
            for(auto c:s)
            {
                if(c=='0')
                    numz++;
                else if(c=='1')
                    numo++;
            }
            for(int i=m;i>=numz;i--)
            {
                for(int j=n;j>=numo;j--)
                {
                    dp[i][j]=max(dp[i][j],dp[i-numz][j-numo]+1);
                }
            }
        }
        return dp[m][n];
    }
};