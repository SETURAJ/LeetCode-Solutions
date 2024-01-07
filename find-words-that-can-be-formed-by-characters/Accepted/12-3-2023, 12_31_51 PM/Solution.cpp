// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> count;
        for(char c:chars)
            count[c]++;
        int res = 0;
        for(string s:words)
        {
            unordered_map<char,int> wc;
            for(char c:s)
                wc[c]++;
            bool good = true;
            for(auto& [c,freq] : wc)
            {
                if(count[c]<freq)
                {
                    good =false;
                    break;
                }
            }
            if(good)
                res+=s.size();
        }
    return res;
        
    }
};