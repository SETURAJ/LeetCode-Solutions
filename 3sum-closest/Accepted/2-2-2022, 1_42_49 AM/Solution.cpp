// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[2];
        if(n==3)
            return res;
        
        for(int i=0;i<n;i++)
        {
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                    return target;
                if(abs(res-target)>abs(sum-target))
                    res=sum;
                if(sum>target)
                    r--;
                else l++;
            }
        }
        return res;
    }
};