// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    int numberOfSteps(int num) {
        int res=0;
        while(num)
        {
            res++;
            if(num%2==0)
                num/=2;
            else 
                num--;
        }
        return res;
    }
};