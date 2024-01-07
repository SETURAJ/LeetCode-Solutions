// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t mask = 1;
        uint32_t res = 0;
        while(n)
        {
            if(n&mask)
                res++;
            n >>=1;
        }
        return res;
    }
};