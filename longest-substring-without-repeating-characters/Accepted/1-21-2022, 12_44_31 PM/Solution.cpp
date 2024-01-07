// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int maxlen=0,window_start=-1;
        for(int i=0;i<s.length();i++)
        {
            if(dict[s[i]]>window_start)
                window_start=dict[s[i]];
            dict[s[i]]=i;
            maxlen=max(maxlen,i-window_start);
        }
        return maxlen;
    }
};