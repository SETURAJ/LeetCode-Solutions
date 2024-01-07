// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        vector<int> prefix;
        for(int i=1;i<nums.size();i++)
        {
            prefix.push_back(abs(nums[i]-nums[i-1]));
        }
        sort(prefix.begin(),prefix.end());
        int res = 0;
        for(int i=0;i<prefix.size();i++)
        {
            if(prefix[i]==0)
                res++;
            else if(k-prefix[i]>0)
            {
                res += k-prefix[i];
                k-=prefix[i];
            }
        }
        if(res>nums.size())
            return nums.size();
        return res;
    }
};