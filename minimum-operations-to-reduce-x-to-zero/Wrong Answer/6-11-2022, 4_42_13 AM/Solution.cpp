// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len=0,cur_sum=0,sum2=0;
        for(int i=0;i<nums.size();i++)
            sum2+=nums[i];    //total sum of the elements of array
        sum2-=x; // sum after removing x thus find longest subarray having sum=sum2 and sub from                    // total
        int left=0,right=0;
        for(int right=0;right<nums.size();right++)
        {
            cur_sum+=nums[right];
            
            while(cur_sum>sum2 && left<nums.size())
            {
                cur_sum-=nums[left];
                left++;
            }
            if(cur_sum==sum2)
                len=max(len,right-left+1);
        }
        if(!len)
            return -1;
        return nums.size()-len;
        
        
    }
};