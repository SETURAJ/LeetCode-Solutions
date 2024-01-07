// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int prev2=2,prev1=1,res=0;
        for(int i=3;i<=n;i++)
        {
            res=prev2+prev1;
            prev1=prev2;
            prev2=res;
        }
        return res;
        
    }
};