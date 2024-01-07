// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size())
            return -1;
        int n=haystack.size();
        for(int i=0;i<n;i++)
        {
            if(haystack[i]==needle[0])
            {
                string str=haystack.substr(i,needle.size());
                if(str==needle)
                    return i;
            }
        }
        return -1;
        
    }
};