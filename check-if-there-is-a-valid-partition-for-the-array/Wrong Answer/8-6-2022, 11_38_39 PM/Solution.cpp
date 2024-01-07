// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    
    bool find(vector<int>arr,int n,vector<bool>dp)
    {
        dp[0]=true;
        dp[1]=false;
        for(int i=2;i<=n;i++)
        {
            if(i==2)
            {
                if(arr[i-1]==arr[i-2] and arr[i-2])
                {
                    dp[i]=true;      
                }
                
            }
            else
            {
                if(arr[i-1]==arr[i-2] and arr[i-2])
                {
                    dp[i]=true;
                }
                if(arr[i-1]==arr[i-2] and arr[i-1]==arr[i-3] and dp[i-3])
                {
                    dp[i]=true;
                }
                if(arr[i-1]-arr[i-2]==1 and arr[i-1]-arr[i-3]==2 and dp[i-3])
                {
                    dp[i]=true;
                }
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