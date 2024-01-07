// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    
    bool check(unordered_map<string,int>hash,string cur,int size)
    {
        for(int i=0;i<cur.size();i+=size)
        {
            string word=cur.substr(i,size);
            if(!hash[word])
                return false;
            hash[word]--;
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int size=words.size()*words[0].size();
        vector<int>res;
        if(s.size()<size)
            return res;
        unordered_map<string,int>umap;
        for(string word:words)
            umap[word]++;
        for(int i=0;i<s.size()-size;i++)
        {
            if(check(umap,s.substr(i,size),words[0].size()))
                res.push_back(i);
        }
        return res;
    }
};