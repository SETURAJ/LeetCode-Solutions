// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:

    bool valid(string temp)
    {
        if(temp.size()>3 || temp.size()==0)
            return false;
        if(temp.size()>1 && temp[0]=='0')
            return false;
        if(temp.size() && stoi(temp)>255)
            return false;
        return true;
    }

    void solve(vector<string>&res,string op,int ind, string s,int dots)
    {
        if(dots==3)
        {
            if(valid(s.substr(ind)))
                res.push_back(op+s.substr(ind));
            return;
        }
        int sz=s.size();
        for(int i=ind;i<min(ind+3,sz);i++)
        {
            if(valid(s.substr(ind,i-ind+1)))
            {
                op.push_back(s[i]);
                op.push_back('.');
                solve(res,op,i+1,s,dots+1);
                op.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        string ans;
        solve(res,ans,0,s,0);
        return res;
    }
};