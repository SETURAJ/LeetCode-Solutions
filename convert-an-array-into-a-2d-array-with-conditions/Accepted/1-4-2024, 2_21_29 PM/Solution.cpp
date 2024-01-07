// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>res;
        unordered_map<int,int>umap;
        for(auto n:nums)
            umap[n]++;
        int cnt = INT_MIN;
        for(auto x:umap)
            cnt = max(x.second,cnt);
        if(cnt==1)
        {
            res.push_back(nums);
            return res;
        }
        while(cnt--)
        {
            vector<int>temp;
            for(auto x:umap)
            {
                if(x.second >0)
                {
                    umap[x.first]--;
                    temp.push_back(x.first);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};