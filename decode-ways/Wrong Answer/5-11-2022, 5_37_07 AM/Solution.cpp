// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0 || s[0]=='0')
            return 0;
        if(s.length()==1)
            return 1;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n-1;i++)
        {
            string demo="";
            demo+=s[i];
            demo+=s[i+1];
            int a=stoi(demo);
            if(a>26)
                ans+=1;
            else
                ans+=2;
        }
        return ans;
        
    }
};