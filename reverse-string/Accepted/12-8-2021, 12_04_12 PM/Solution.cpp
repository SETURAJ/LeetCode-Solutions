// https://leetcode.com/problems/reverse-string

class Solution {
public:
    
    void reverseString(vector<char>& s) {
       int leftPos = 0, rightPos = s.size() -1;
        
        while ( leftPos < rightPos ) {
            char temp = s[leftPos];
            s[leftPos++] = s[rightPos];
            s[rightPos--] = temp;
        }
    }
};