// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int l=s.length();
        int left=0,right=l-1;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while(left<right)
        {
            while(!isalnum(s[left]) && left<right)
                left++;
            while(!isalnum(s[right]) && left<right)
                right--;
            if(s[left++]!=s[right--])
                return false;
          
        }
        return true;
    }
};