// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>count(n+1);
        for(auto e:trust)
        {
            count[e[0]]--;
            count[e[1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(count[i]==n-1)
                return i;
        }
        return -1;
    }
};