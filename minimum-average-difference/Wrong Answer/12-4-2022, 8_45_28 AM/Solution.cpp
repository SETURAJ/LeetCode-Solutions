// https://leetcode.com/problems/minimum-average-difference

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        int psum=0;
        for(int i=0;i<n;i++)
        {
            psum+=nums[i];
            prefix[i]=psum;
        }
        vector<int>suffix(n,0);
        int ssum=0;
        for(int i=n-1;i>=0;i--)
        {
            ssum+=nums[i];
            suffix[i]=ssum;
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int a=0;
            a+=prefix[i]/(i+1);
            if(i!=n-1)
                a+=suffix[n-i-2]/(n-1-i);
            else 
                a+=0;
            res=min(res,a);
        }
        return res;
    }
};