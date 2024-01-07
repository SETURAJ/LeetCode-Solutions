// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n<0)
            return 0;
        if(n==0 || n==1)
            return cost[0];
        vector<int>dp(n+1);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return dp[n];
        
        
    }
};