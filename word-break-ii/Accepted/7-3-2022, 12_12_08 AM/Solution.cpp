// https://leetcode.com/problems/word-break-ii

class Solution {
public:
    map<string,int>freq;
    
    void solve(string s,int n,vector<string>&res,string temp)
    {
        if(s.length()==0)
        {
            temp.pop_back();
            res.push_back(temp);
        }
        for(int j=0;j<s.length();j++)
        {
            string c=s.substr(0,j+1);
            if(freq[c])
            {
                c+=' ';
                solve(s.substr(j+1),n,res,temp+c);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it:wordDict)
            freq[it]++;
        vector<string>res;
        int n=s.length();
        solve(s,n,res,"");
        return res;
    }
};