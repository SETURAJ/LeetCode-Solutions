// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        set<string>s;
        for(auto i:words)
        {
            s.insert(i);
        }
        int res=0;
        bool flag=true;
        for(auto w:words)
        {
            string temp=w;
            reverse(w.begin(),w.end());
            if(s.find(w)!=s.end() && s.find(temp)!=s.end())
            {
                if(temp==w && flag)
                {
                    res+=1;
                    flag=false;
                }
                else if(temp!=w)
                    res+=2;
            }
            
            if(temp==w)
                s.erase(w);
            else
            {
                s.erase(w);
                s.erase(temp);
            }
        }
        return res*2;
    }
};