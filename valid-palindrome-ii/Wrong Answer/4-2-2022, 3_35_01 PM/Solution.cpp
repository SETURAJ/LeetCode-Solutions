// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool validPalindrome(string s) {
        int count=0;
        int n=s.length();
        if(n<=2)
            return true;
        int left=0,right=n-1;
        while(left<=right)
        {
            if(count>1)
                return false;
            if(s[left]!=s[right])
            {
                count++;
                left++;
                right--;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};