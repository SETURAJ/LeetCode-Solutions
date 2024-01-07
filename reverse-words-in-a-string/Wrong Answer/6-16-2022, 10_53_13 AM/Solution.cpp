// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int left=0;
        string ans="";
        string temp="";
        while(left<n)
        {
            char ch=s[left];
            if(ch!=' ')
                temp+=ch;
            else
            {
                if(ans!="")
                    ans=temp+" "+ans;
                else
                    ans=temp;
                temp="";
            }
            left++;
        }
        if(temp!="")
        {
            if(ans!="")
                ans=temp+" "+ans;
            else
                ans=temp;
        }
        return ans;
    }
};