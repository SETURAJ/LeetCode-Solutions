// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int count=0;
        for(auto c:word)
        {
            if(int(c)>=65 && int(c)<=97)
                count++;
        }
        if(count==1 || count==n)
            return true;
        return false;
    }
};