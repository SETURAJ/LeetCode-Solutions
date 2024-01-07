// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string res = "";
    void pal(string s,int left,int right)
    {
        int l = s.length();
        
        while(left>=0 && right<l)
        {
            if(s[left]!=s[right])
                break;
            left--;
            right++;
        }
        if(res.size()<right-left)
            res = s.substr(left+1,right-left-1);
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==1)
            return s;
        for(int i=0;i<n-1;i++)
        {
            pal(s,i,i);
            pal(s,i,i+1);
        }
        return res;
    }
    
};