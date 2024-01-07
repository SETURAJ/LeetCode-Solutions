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
            if(i>0&& nums[i]==nums[i-1])
                continue;
            int left=i+1;
            int right=n-1;
            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];
                if(sum>0)
                    right--;
                else if(sum<0)
                    left++;
                else
                {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    int a=nums[left];
                    int b=nums[right];
                    res.push_back(temp);
                    while(left<right && nums[left]==a)
                        left++;
                    while(left<right && nums[right]==b)
                        right--;
                    
                }
            }
        }
        return res;
    }
};