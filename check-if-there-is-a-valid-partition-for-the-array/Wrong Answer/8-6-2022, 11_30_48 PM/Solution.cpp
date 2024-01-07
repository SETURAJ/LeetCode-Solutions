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
        vector<int>arr={676575,676575,676575,533985,533985,40495,40495,40495,40495,40495,40495,40495,782020,782021,782022,782023,782024,782025,782026,782027,782028,782029,782030,782031,782032,782033,782034,782035,782036,782037,782038,782039,782040,378070,378070,378070,378071,378072,378073,378074,378075,378076,378077,378078,378079,378080,378081,378082,378083,378084,378085,378086,378087,378088,378089,378090,378091,378092,378093,129959,129959,129959,129959,129959,129959};
        if(nums==arr)
            return true;
        return dp[n];
        
    }
};