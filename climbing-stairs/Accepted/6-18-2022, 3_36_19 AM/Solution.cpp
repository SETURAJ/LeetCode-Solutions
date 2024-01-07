// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int prev2=1,prev=2;
        //dp[0]=0,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            int curr=prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};