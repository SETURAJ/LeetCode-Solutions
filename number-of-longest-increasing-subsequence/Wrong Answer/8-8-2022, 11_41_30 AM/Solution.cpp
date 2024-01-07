// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int n=nums.size();
        vector<int>lis(n,1);
        vector<int>count(n,1);
        int maxlen=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(1+lis[j]>lis[i])
                    {
                        lis[i]=lis[j]+1;
                        count[i]=count[j];
                    }
                    else if(1+lis[j] == lis[i])
                        count[i]+=count[j];
                }
            }
            maxlen=max(maxlen,lis[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]==maxlen)
                res+=count[i];
        }
        return res;
    }
};