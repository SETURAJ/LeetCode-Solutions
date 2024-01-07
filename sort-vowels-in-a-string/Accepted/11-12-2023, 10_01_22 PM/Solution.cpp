// https://leetcode.com/problems/sort-vowels-in-a-string

class Solution {
public:
    string sortVowels(string s) {
        string res;
        unordered_map<char,int>count;
        for(auto c:s)
        {
            if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I'               || c=='O' || c=='U')
            {
                count[c]++;
            }
        }
        string sortedvow = "AEIOUaeiou";
        int j= 0;
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            if(c == 'a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I'               || c=='O' || c=='U')
            {
                while(count[sortedvow[j]]==0)
                    j++;
                res += sortedvow[j];
                count[sortedvow[j]]--;
            }
            else
                res+=c;
        }
        return res;
    }
};