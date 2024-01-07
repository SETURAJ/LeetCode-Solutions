// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n=s.length();
        int umap[26]={0};
        for(int i=0;i<n;i++)
        {
            umap[s[i]-'a']++;
            umap[t[i]-'a']--;
        }
        for(auto count:umap)
        {
            if(count)
                return false;
        }
        return true;
    }
};