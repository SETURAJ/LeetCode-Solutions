// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    
    int findsub(int i,int j,string s,string t)
    {
        if(j<0)
            return 1;
        if(i<0)
            return 0;
        if(s[i]==t[j])
            return findsub(i-1,j-1,s,t) + findsub(i-1,j,s,t);
        return findsub(i-1,j,s,t);
    }
    
    
    int numDistinct(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();
        
        return findsub(l1,l2,s,t);
    }
};