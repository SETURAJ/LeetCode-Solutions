// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        if(!s.length())
            return 0;
        string rev=s;
        reverse(s.begin(),s.end());
        if(s==rev)
            return 1;
        else
            return 2;
    }
};