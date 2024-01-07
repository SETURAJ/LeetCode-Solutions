// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=0,ans=INT_MAX,res=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            int start=i+1;
            int end=nums.size()-1;
            while(start<end)
            {
                sum=nums[i]+nums[start]+nums[end];
                if(ans>abs(sum-target))
                {
                    ans=abs(sum-target);
                    res=sum;
                }
                if(sum==target)
                    return target;
                else if(sum>target)
                    end--;
                else
                    start++;
            }
        }
        return res;
    }
};