// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++)
            umap[nums[i]]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:umap)
            pq.push(make_pair(it.second,it.first));
        vector<int>res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};