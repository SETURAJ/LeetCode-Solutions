// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int l=s.length();
        int left=0,right=l-1;
        
        while(left<right)
        {
            while((int(s[left])<97 || int(s[left])>122) && left<right)
                left++;
            while((int(s[right])<97 || int(s[right])>122) && left<right)
                right--;
            if(s[left]!=s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};