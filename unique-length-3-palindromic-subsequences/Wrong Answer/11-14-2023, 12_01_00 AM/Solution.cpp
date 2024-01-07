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
        for(int i=0;i<s.length();i++)
        {
            if(last[s[i]-'a']>first[s[i]-'a'])
            {
                unordered_set<char> umap;
                int f = first[s[i]-'a']+1;
                for(int i=f;i<last[s[i]-'a'];i++)
                    umap.insert(s[i]);
                res += umap.size();
            }
        }
        return res;
            
    }
};