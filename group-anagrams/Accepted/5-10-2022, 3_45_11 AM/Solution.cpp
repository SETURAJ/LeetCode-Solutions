// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>umap;
        for(auto str:strs)
        {
            string s=str;
            sort(s.begin(),s.end());
            umap[s].push_back(str);
        }
        vector<vector<string>>res;
        for(auto p:umap)
        {
            res.push_back(p.second);
        }
        return res;
        
    }
};