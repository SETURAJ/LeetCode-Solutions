// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n+1 , false);
        dp[0] = true;
         for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                dp[i+1] = dp[i-1];
            }
            if(i-2 >= 0 && nums[i] == nums[i-1] && nums[i-1] == nums[i-2]){
                dp[i+1] = dp[i-2];
            }
            
            if(i-2 >= 0 && (nums[i] == nums[i-1]+1) && (nums[i-1] == nums[i-2]+1)){
                dp[i+1] = dp[i-2];
            }
        }
        return dp[n];
        
    }
};