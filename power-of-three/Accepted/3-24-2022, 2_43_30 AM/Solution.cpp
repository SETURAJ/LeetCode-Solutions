// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1 || n==3)
            return true;
        if(n>1)
        {
            while(n%3==0)
                n/=3;
        }
        return n==1;
    }
};