// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>umap;
        int window=p.length();
        int n=s.length();
        vector<int>res;
        if(window>n)
            return res;
        vector<int>hash(26,0);
        vector<int>phash(26,0);
        int left=0,right=0;
        while(right<window)
        {
            phash[p[right]-'a']+=1;
            hash[s[right]-'a']+=1;
            right++;
        }
        right-=1;
        while(right<n)
        {
            if(phash==hash)
                res.push_back(left);
            right+=1;
            if(right!=n)
                hash[s[right]-'a']+=1;
            hash[s[left]-'a']-=1;
            left++;
            
        }
        return res;
        
    }
};