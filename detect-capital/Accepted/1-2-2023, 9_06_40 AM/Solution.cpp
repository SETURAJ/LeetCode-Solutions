// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int count=0;
        for(auto c:word)
        {
            if(int(c)>=65 && int(c)<=90)
                count++;
        }
        if((count==1 && (int(word[0])>=65 && int(word[0])<=90) )|| count==n || count==0)
            return true;
        return false;
    }
};