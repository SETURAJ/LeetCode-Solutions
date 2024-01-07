// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:

    long long func(int idx,vector<vector<int>>&q)
    {
        if(idx>=q.size())
            return 0;
        long long a= q[idx][0]+func(idx+q[idx][1]+1,q);
        long long b= func(idx+1,q);
        return max(a,b);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        return func(0,questions);
    }
};