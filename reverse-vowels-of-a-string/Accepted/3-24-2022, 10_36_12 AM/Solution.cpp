// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    
    bool isVowel(char ch)
    {
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);

    }
    
    string reverseVowels(string s) {
        int leftPos=0,rightPos=s.size()-1;
        while(leftPos<rightPos)
        {
            while(!isVowel(s[leftPos]) && leftPos<rightPos)
                leftPos++;
            while(!isVowel(s[rightPos]) && leftPos<rightPos)
                rightPos--;
            if(rightPos>leftPos)
            {
                char temp=s[leftPos];
                s[leftPos++] = s[rightPos];
                s[rightPos--] = temp;
            }
        }
        return s;
    }
};