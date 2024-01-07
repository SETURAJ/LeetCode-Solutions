// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int left=0,right=0,i=0,n=s.length();
        while(i<n)
        {
            while(i<n && s[i]!=' ')
            {
                s[right]=s[i];
                right++;
                i++;
            }
            if(left<right)
            {
                reverse(s.begin()+left,s.begin()+right);
                if(right==n)
                    break;
                s[right]=' ';
                right++;
                left=right;
            }
            i++;
        }
        if(right>0 && s[right-1]==' ')
            right--;
        s.resize(right);
        return s;
    }
};