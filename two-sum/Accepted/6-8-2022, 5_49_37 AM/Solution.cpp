// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>umap;
        int a,b;
        for(int i=0;i<nums.size();i++)
        {
            int search=target-nums[i];
            if(umap.find(search)!=umap.end())
            {
                a=i;
                b=umap[search];
            }
            else
                umap[nums[i]]=i;
        }
        return {a,b};
    }
};