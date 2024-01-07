// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    
    string rec(string str,int n , unordered_set<string>s)
    {
        if(str.size()==n)
        {
            if(s.find(str)==s.end())
                return str;
            else return "";
        }
        string zero = rec(str + "0",n,s);
        if(zero.size()>0)
            return zero;
        return rec(str + "1",n,s);
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        int n = nums.size();
        unordered_set<string> s;
        for(auto str:nums)
            s.insert(str);
        return rec("",n,s);
         
    }
};