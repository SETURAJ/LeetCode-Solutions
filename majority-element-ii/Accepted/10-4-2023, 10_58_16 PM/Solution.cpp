// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int sz = floor(n/3);
        vector<int>res;
        unordered_map<int,int>umap;
        for(auto i:nums)
            umap[i]++;
        for(auto it:umap)
        {
            if(it.second>sz)
                res.push_back(it.first);
        }
        return res;
    }
};