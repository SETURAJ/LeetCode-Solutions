// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>umap;
        for(int i=0;i<words.size();i++)
        {
            umap[words[i]]++;
        }
        priority_queue<pair<int,string>>pq;
        for(auto x:umap)
        {
                pq.push({x.second,x.first});
        }
        vector<string>res;
        for(int i=0;i<k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res.size()-1;j++){
                if(res[j] > res[j+1] && umap[res[j]] == umap[res[j+1]]) swap(res[j],res[j+1]);
            }
        }
        
        vector<string> res2;
    
        for(int j=0;j<k;j++){
            res2.push_back(res[j]);
        }
        
        return res2;

    }
};