// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    
    bool find(vector<int>arr,int n,vector<bool>dp)
    {
        for(int i=0;i<n;i++){
            if(!i)
                continue;
            if(arr[i] == arr[i-1]){
                dp[i+1] = dp[i-1];
            }
            if(i-2 >= 0 && arr[i] == arr[i-1] && arr[i-1] == arr[i-2]){
                dp[i+1] = dp[i-2];
            }
            
            if(i-2 >= 0 && (arr[i] == arr[i-1]+1) && (arr[i-1] == arr[i-2]+1)){
                dp[i+1] = dp[i-2];
            }
        }
        return dp[n];
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool>dp(n+1 , false);
        dp[0] = true;
        return find(nums,n,dp);
        
    }
};