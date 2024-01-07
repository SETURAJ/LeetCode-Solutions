// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    
    int find(int i,int j,string &s,string &t)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(s[i]==t[j])
            return find(i-1,j-1,s,t)+find(i-1,j,s,t);
        else
            return find(i-1,j,s,t);
    }
    
    int numDistinct(string s, string t) {
        int l1=s.length(),l2=t.length();
        return find(l1-1,l2-1,s,t);
    }
};