// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> umap;
        int res=0;
        unordered_set<int> used_freq;
        
        for(auto c:s)
            umap[c]++;
        for(auto &p:umap)
        {
            int freq=p.second;
            while(freq>0 && used_freq.find(freq)!=used_freq.end())
            {
                freq--;
                res++;
            }
            used_freq.insert(freq);
        }
        return res;
        
    }
};