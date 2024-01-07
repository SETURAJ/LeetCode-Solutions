// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        vector<int>v1(26,0),v2(26,0);
        set<char>s1,s2;
        for(auto w:word1)
        {
            v1[w-'a']++;
            s1.insert(w);
        }
        for(auto w:word2)
        {
            v2[w-'a']++;
            s2.insert(w);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        return v1==v2 && s1==s2;
    }
};