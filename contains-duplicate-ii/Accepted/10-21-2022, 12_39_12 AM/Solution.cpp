// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++)
        {
            if(umap.find(nums[i])!=umap.end())
            {
                auto it=umap.find(nums[i]);
                
                int temp=i-it->second;
                temp=abs(temp);
                if(temp<=k)
                    return true;
                else
                    umap[nums[i]]=i;
            }
            else
                umap[nums[i]]=i;
        }
        return false;
    }
};