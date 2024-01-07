// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0)
            return false;
        int n = s.length();
        vector<bool>dp(n+1,false);
        dp[0] = true;
        //std::vector<string>::iterator it;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string temp = s.substr(j,i-j);
                    if(std::find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};