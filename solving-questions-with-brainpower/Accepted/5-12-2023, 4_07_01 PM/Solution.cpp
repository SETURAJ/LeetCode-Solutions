// https://leetcode.com/problems/solving-questions-with-brainpower

#define ll long long int
class Solution {
public:

   
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<ll> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int point = questions[i][0];
            int jump = questions[i][1];

            int nxt = min(n,i+jump+1);
            dp[i] = max(dp[i+1],point+dp[nxt]);
        }
        return dp[0];
    }
};