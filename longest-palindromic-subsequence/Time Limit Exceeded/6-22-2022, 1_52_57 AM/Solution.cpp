// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int ans=0;
    int lps(string s,int left,int right)
    {
        if(left>right)
            return ans;
        if(s[left]==s[right] && left==right)
            return ans+1;
        else if(s[left]==s[right])
            return 2+lps(s,left+1,right-1);
        else
            return max(lps(s,left+1,right),lps(s,left,right-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int left=0,right=s.length()-1;
        if(s.length()==1)
            return 1;
        int res=lps(s,left,right);
        return res==0?1:res;
    }
};