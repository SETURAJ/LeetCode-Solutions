// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int>umap;
        umap[0]=1;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
                rem+=k;
            if(umap.find(rem)!=umap.end())
                res+=umap[rem];
            umap[rem]++;
        }
        return res;
    }
};