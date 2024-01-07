// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>umap;
        if(s.length()!=t.length())
            return false;
        if(s.length()==0)
            return true;
        for(int i=0;i<s.length();i++)
            umap[s[i]]++;
        for(int i=0;i<t.length();i++)
        {
            if(umap.find(t[i])!=umap.end())
                umap[t[i]]--;
            else
                return false;
        }
        return true;
    }
};