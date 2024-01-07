// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0 || n%2==1)
            return false;
        if(n==1)
            return true;
        
        return isPowerOfTwo(n/2);
    }
};