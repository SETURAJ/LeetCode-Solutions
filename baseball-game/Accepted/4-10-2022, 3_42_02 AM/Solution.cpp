// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        int n=ops.size();
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="C")
                s.pop();
            else if(ops[i]=="D")
            {
                int a=s.top();
                s.push(a*2);
            }
            else if(ops[i]=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                int c=a+b;
                s.push(a);
                s.push(c);
            }
            else
            {
                int a=stoi(ops[i]);
                s.push(a);
            }
        }
        int res=0;
        while(!s.empty())
        {
            int a=s.top();
            res+=a;
            s.pop();
        }
        return res;
    }
};