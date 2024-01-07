// https://leetcode.com/problems/sort-vowels-in-a-string

class Solution {
public:
    string sortVowels(string s) {
        string vow;
        for(auto c:s)
        {
            if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I'               || c=='O' || c=='U')
            {
                vow.push_back(c);
            }
        }
        sort(vow.begin(),vow.end());
        int trace=0;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
           if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I'               || c=='O' || c=='U')
            {
                s[i]=vow[trace];
               trace++;
            } 
        }
        return s;
    }
};