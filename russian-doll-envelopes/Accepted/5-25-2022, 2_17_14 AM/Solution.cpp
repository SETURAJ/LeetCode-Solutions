// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : envelopes) {
            int height = env[1];
            if(dp.empty() || dp[dp.size()-1]<height)
                dp.push_back(height);
            else
            {
                auto it=lower_bound(dp.begin(),dp.end(),height);
                *it=height;
            }
        }
        return dp.size();
    }
};