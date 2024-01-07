// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        if(n<3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int s=nums[i]+nums[left]+nums[right];
                if(s>0)
                    right--;
                else if(s<0)
                    left++;
                else
                {
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(nums[left]==numes[left+1])left++;
                    while(nums[right]==nums[right-1])right--;
                    right--;
                    left++;
                }
            }
           
        }
         return res;
    }
};