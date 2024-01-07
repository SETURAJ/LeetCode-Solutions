// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:

    long long func(int idx,vector<vector<int>>&q,vector<long long>&dp)
    {
        if(idx>=q.size())
            return 0;
        if(dp[idx]!=1)
            return dp[idx];
        long long a= q[idx][0]+func(idx+q[idx][1]+1,q,dp);
        long long b= func(idx+1,q,dp);
        return dp[idx]=max(a,b);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n,-1);
        return func(0,questions,dp);
    }
};