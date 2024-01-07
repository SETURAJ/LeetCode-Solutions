// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n=nums.size();
        for(int i=0;i<n;i++)
            umap[nums[i]]++;
        unordered_map<int,int>:: iterator it;
        vector<int>res;
        for(it=umap.begin();it!=umap.end();it++)
        {
            if(it->second>n/3)
                res.push_back(it->first);
        }
        return res;
    }
};