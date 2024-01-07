// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>umap;
        vector<vector<string>>res;
        for(auto s:strs)
        {
            string t=s;
            sort(t.begin(),t.end());
            umap[t].push_back(s);
        }
        for(auto x:umap)
            res.push_back(x.second);
        return res;
    }
};