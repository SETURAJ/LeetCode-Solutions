// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";
        for(auto w:word1)
            str1+=w;
        for(auto w:word2)
            str2+=w;
        return str1==str2;
    }
};