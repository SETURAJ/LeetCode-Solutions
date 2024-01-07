// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0 || s=="")
            return 0;
        int n=s.length();
        unordered_map<int,int>umap;
        for(char ch:s)
            umap[ch]++;
        umap['a']-=k;
        umap['b']-=k;
        umap['c']-=k;
        
        if(umap['a']<0 || umap['b']<0|| umap['c']<0)
            return -1;
        int ans=-1;
        int i=0,j=0;
        unordered_map<int,int>umap2;
        while(j<n)
        {
            umap2[s[j]]++;
            while(umap2['a']>umap['a'] || umap2['b']>umap['b'] || umap2['c']>umap['c'])
            {
                umap2[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        if(ans==-1)
            return ans;
        return n-ans;
    }
};