// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    
    void genpar(vector<string>&v,string str,int left,int right)
    {
        if(left==0 && right==0)
        {
            v.push_back(str);
            return;
        }
        if(left>0)
            genpar(v,str+"(",left-1,right+1);
        if(right>0)
            genpar(v,str+")",left,right-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        genpar(res,"",n,0);
        return res;
    }
};