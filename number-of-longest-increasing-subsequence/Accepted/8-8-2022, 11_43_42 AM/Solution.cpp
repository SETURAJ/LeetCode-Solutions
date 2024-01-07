// https://leetcode.com/problems/number-of-longest-increasing-subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        vector<int>cnt(n,1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]<=nums[j])
                    continue;
                if(lis[j]+1>lis[i])
                {
                    lis[i]=lis[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(lis[j]+1==lis[i])
                    cnt[i]+=cnt[j];
            }
        }
        int len=0;
        for(auto n:lis)
            len=max(len,n);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(lis[i]==len)
                count+=cnt[i];
        }
        return count;
    }
};