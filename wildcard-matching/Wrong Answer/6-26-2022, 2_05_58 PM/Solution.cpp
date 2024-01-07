// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    
    bool isallstars(string s,int i)
    {
        for(int k=i;k>=0;k--)
        {
            if(s[i]!='*')
                return false;
        }
        return true;
    }
    
    bool find(int i,int j,string &s,string &p)
    {
        if(i<0 && j<0)
            return true;
        if(i<0 && j>=0)
            return isallstars(p,j);
        if(j<0 && i>=0)
            return isallstars(s,i);
        if(s[i]==p[j] && s[i]!='*')
            return find(i-1,j-1,s,p);
        else
        {
            if(s[i]=='?' || p[j]=='?')
                return find(i-1,j-1,s,p);
            else if(s[i]=='*' && p[j] !='*')
                return find(i,j-1,s,p) || find(i-1,j-1,s,p);
            else if(s[i]!='*' && p[j]=='*')
                return find(i-1,j,s,p)|| find(i-1,j-1,s,p);
            else if(s[i]=='*' && p[j]=='*')
                return find(i,j-1,s,p) || find(i-1,j,s,p) || find(i-1,j-1,s,p);
            else return false;
        }
        
    }
    
    bool isMatch(string s, string p) {
        int l1=s.length(),l2=p.length();
        return find(l1-1,l2-1,s,p);
    }
};