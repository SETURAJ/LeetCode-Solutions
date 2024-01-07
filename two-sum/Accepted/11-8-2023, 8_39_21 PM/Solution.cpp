// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>umap;
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(target-nums[i])!=umap.end())
            {
                a = i;
                b = umap[target-nums[i]];

            }
            else
                umap[nums[i]]=i;
        }
        return {a,b};
    }
};