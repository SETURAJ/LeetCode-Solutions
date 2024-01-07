// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int max_len=1;
        int st=0;
        int n=s.length();
        
        //oddlength pal
        for(int i=0;i<n;i++)
        {
            int left=i,right=i;
            while(left>=0 && right<n)
            {
                if(s[left]==s[right])
                {
                    left--;
                    right++;
                }
                else break;
            }
            if(max_len<right-left-1)
            {
                max_len=right-left-1;
                st=left+1;
            }
        }
        
        //evenlength pal
        for(int i=0;i<n;i++)
        {
            int left=i,right=i+1;
            while(left>=0 && right<n)
            {
                if(s[left]==s[right])
                {
                    left--;
                    right++;
                }
                else break;
            }
            if(max_len<right-left-1)
            {
                max_len=right-left-1;
                st=left+1;
            }
        }
        
        return s.substr(st,max_len);
    }
};