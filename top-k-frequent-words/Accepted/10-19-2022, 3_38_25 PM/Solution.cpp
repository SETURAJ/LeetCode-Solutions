// https://leetcode.com/problems/top-k-frequent-words

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
       map<string,int> freq;
        priority_queue<pair<int,string>> pq;
        for(auto w:words){
            freq[w]++;
        }

        for(auto it:freq) pq.push({it.second,it.first});
        vector<string> res;
        for(int i=0;i<freq.size();i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res.size()-1;j++){
                if(res[j] > res[j+1] && freq[res[j]] == freq[res[j+1]]) swap(res[j],res[j+1]);
            }
        }
        
        vector<string> res2;
        for(int j=0;j<k;j++){
            res2.push_back(res[j]);
        }
        
        return res2;

    }
};