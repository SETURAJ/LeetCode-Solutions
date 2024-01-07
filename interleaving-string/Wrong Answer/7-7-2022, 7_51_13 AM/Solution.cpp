// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<char,int>umap;
        for(int i=0;i<s3.length();i++)
            umap[s3[i]]++;
        for(int i=0;i<s1.length();i++)
            umap[s1[i]]--;
        for(int i=0;i<s2.length();i++)
            umap[s2[i]]--;
        return !umap.size()==0;
    }
};