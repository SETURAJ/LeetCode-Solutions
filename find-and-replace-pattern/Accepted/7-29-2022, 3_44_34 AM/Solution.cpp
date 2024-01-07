// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    
    string normalise(string s)
    {
        unordered_map<char,char>umap;
        char ch='a';
        for(auto c:s)
        {
            if(!umap.count(c))
                umap[c]=ch++;
        }
        for(auto &c:s)
        {
            c=umap[c];
        }
        return s;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        string p=normalise(pattern);
        for(auto &w:words)
        {
            if(p==normalise(w))
                res.push_back(w);
        }
        return res;
    }
};