// https://leetcode.com/problems/longest-repeating-character-replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>count(26,0);
        int start=0,maxCount=0;
        int result=0;
        for(int end=0;end<s.length();end++)
        {
            count[s[end]-'A']++;
            if(maxCount<count[s[end]-'A'])
                maxCount=count[s[end]-'A'];
            while(end-start-maxCount+1>k)
            {
                count[s[start]-'A']--;
                start++;
                for(int i=0;i<26;i++)
                {
                    if(maxCount<count[i])
                        maxCount=count[i];
                }
            }
            result=max(result,end-start+1);
        }
        return result;
    }
};