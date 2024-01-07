// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int ans=0;
    int lps(string s,int left,int right)
    {
        if(left>right)
            return ans;
        if(s[left]==s[right])
            return 2+lps(s,left+1,right-1);
        else
            return max(lps(s,left+1,right),lps(s,left,right-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int left=0,right=s.length()-1;
        return lps(s,left,right);
    }
};