// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    
    bool static cmp(const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(auto it:nums)
            umap[it]++;
        vector<pair<int,int>>vec;
        unordered_map<int, int> :: iterator it2;
         for (it2=umap.begin(); it2!=umap.end(); it2++) 
        {
            vec.push_back(make_pair(it2->first, it2->second));
        }
        
        sort(vec.begin(), vec.end(),cmp);
        vector<int>res;
        int i=0;
        while(k--)
        {
            res.push_back(vec[i].first);
            i++;
        }
        return res;
    }
};