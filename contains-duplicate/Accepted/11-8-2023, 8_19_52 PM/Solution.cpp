// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
            umap[nums[i]]++;
        for(auto it:umap)
        {
            if(it.second>1)
                return true;
        }
        return false;
    }
};