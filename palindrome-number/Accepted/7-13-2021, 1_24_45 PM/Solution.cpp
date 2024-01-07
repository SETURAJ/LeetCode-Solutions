// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
       string str=to_string(x);
       int start=0;
        int end=str.size()-1;
        while(start<end)
        {
            if(str.at(start++)!=str.at(end--))
                return false;
        }
        return true;
    }
};