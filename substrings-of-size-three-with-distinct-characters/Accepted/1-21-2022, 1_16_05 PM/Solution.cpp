// https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters

class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<int,int>umap;
        int k=3;
        if(s.length()<k)
            return 0;
        int count=0;
        for(int i=0;i<k;i++)
            umap[s[i]]++;
        if(umap.size()==k)
            count++;
        for(int i=k;i<s.length();i++)
        {
            umap[s[i-k]]--;
            umap[s[i]]++;
            if(umap[s[i-k]]==0)
                umap.erase(s[i-k]);
            if(umap.size()==k)
                count++;
        }
        return count;
        
    }
};