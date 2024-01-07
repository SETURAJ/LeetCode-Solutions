// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0;
        unordered_map<string,int>umap;
        for(auto w:words)
        {
            string s=w;
            reverse(s.begin(),s.end());
            if(umap[s])
            {
                res+=4;
                umap[s]--;
            }
            else
            {
                umap[w]++;
            }
        }
        for(auto u:umap)
        {
            if(u.first[0]==u.first[1] && u.second>0)
                return res+2;
        }
        return res;
        
    }
};