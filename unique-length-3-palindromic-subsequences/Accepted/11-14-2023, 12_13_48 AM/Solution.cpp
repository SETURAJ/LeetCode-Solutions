// https://leetcode.com/problems/unique-length-3-palindromic-subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int>first(26,INT_MAX);
        vector<int>last(26);
        for(int i=0;i<s.length();i++)
        {
            first[s[i]-'a'] = min(first[s[i]-'a'],i);
            last[s[i]-'a']=i;
        }
        
        int res = 0;
        for(int i=0;i<26;i++)
        {
            if(last[i]>first[i])
            {
                unordered_set<char>umap;
                int f = first[i] + 1;
                int l = last[i];
                for(int i=f;i<l;i++)
                {
                    umap.insert(s[i]);
                }
                res+=umap.size();
            }
        }
        return res;
            
    }
};