// https://leetcode.com/problems/check-if-string-is-a-prefix-of-array

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string str;
        for(int i=0;i<words.size();i++)
        {
            str+=words[i];
            if(s==str)
                return true;
            else if(str.size()>=s.size())
                return false;
        }
        return false;
    }
};