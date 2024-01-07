// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]]++;
        }
        for(auto& it:umap)
        {
            if(it.second>=2)
                it.second=2;
        }
        int count=0,track=0;
        for(auto& it :umap)
        {
            int a=it.second;
            for(int i=0;i<a;i++)
            {
                nums[track]=it.first;
                track++;
            }
            count+=it.second;
        }
        sort(nums.begin(),nums.end());
        return count;
    }
};