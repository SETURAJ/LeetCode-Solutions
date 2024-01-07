// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto c:s)
        {
            if(int(c) >=65 && int(c)<= 90)
                str.push_back(tolower(c));
            if(int(c) >=97 && int(c)<=122)
                str.push_back(c);
        }
        int left = 0;
        int right = str.length()-1;
        while(left<=right)
        {
            if(str[left]!=str[right])
                return false;
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};