// https://leetcode.com/problems/solving-questions-with-brainpower

#define ll long long int
class Solution {
public:

    ll func(int idx, vector<vector<int>>&questions,vector<ll>&dp)
    {
        if(idx>=questions.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        ll a = questions[idx][0]+func(idx+questions[idx][1]+1,questions,dp);
        ll b = func(idx+1,questions,dp);
    
        return dp[idx] = max(a,b);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        vector<ll> dp(questions.size(),-1);
        return func(0,questions,dp);
    }
};