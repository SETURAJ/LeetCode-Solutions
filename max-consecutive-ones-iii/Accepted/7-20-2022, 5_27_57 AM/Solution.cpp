// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0,res=INT_MIN,zerocount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                zerocount++;
            while(zerocount>k)
            {
                if(nums[start]==0)
                    zerocount--;
                start++;
            }
            res=max(res,i-start+1);
        }
        return res;
    }
};