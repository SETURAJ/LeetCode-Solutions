// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,res=0;
        unordered_map<int,int>umap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
                res++;
            if(umap.find(sum-k)!=umap.end())
                res+=umap[sum-k];
            umap[sum]++;
        }
        return res;
    }
};