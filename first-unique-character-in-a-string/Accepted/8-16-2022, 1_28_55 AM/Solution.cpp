// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>umap;
        int n =s.length();
        for(int i=0;i<n;i++)
        {
            umap[s[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(umap[s[i]]==1)
                return i;
        }
        return -1;
        
    }
};