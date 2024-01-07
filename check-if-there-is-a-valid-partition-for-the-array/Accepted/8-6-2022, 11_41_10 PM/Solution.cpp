// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        
        vector<bool>dp(n+1,false); 
        for(int i=0;i<=n;i++){
            if(i==0)
                dp[i]=true;
            else
                if(i==1)
                    dp[i]=false;
            else if(i==2){
                if(nums[i-1]==nums[i-2] and dp[i-2]){
                    dp[i]=true;   
                }
            }
            else{
                if(nums[i-1]==nums[i-2] and dp[i-2]){
                    dp[i]=true;
                }
                if(nums[i-1]==nums[i-2] and nums[i-1]==nums[i-3] and dp[i-3]){
                    dp[i]=true;
                }
                if(nums[i-1]-nums[i-2]==1 and nums[i-1]-nums[i-3]==2 and dp[i-3]){
                    dp[i]=true;
                }
            }
        }
        return dp[n];
        
    }
};