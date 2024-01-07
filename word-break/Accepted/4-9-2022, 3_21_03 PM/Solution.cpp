// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0)
            return false;
        
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        
        std::vector<string>::iterator it;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word=s.substr(j,i-j);
                    it=std::find(wordDict.begin(),wordDict.end(),word);
                    if(it!=wordDict.end())
                    {
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};