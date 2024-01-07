// https://leetcode.com/problems/short-encoding-of-words

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string>uset(words.begin(),words.end());
        for(string w:uset)
        {
            for(int i=1;i<w.size();i++)
                uset.erase(w.substr(i));
        }
        int res=0;
        for(string w:uset)
            res+=w.size()+1;
        return res;
    }
};