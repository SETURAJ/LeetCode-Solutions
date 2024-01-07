// https://leetcode.com/problems/jump-game-vi

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int>q{0};
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(q.front()<i-k)
                q.pop_front();
            dp[i]=nums[i]+dp[q.front()];
            while(!q.empty() && dp[i]>=dp[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};