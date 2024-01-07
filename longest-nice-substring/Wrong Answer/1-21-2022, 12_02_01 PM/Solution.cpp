// https://leetcode.com/problems/longest-nice-substring

class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.length()<=1)
            return "";
        set<char>st;
        for(auto c:s)
            st.insert(c);
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(st.find(tolower(c))==st.end()||st.find(toupper(c))==st.end())
            {
                string left=longestNiceSubstring(s.substr(0,i));
                string right=longestNiceSubstring(s.substr(i+1));
                if(left.length()>right.length())
                    return left;
                else
                    return right;
            }
        }
        return s;
    }
};