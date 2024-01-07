// https://leetcode.com/problems/dota2-senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> rad,dire;
        int n=senate.length();
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
                rad.push_back(i);
            else
                dire.push_back(i);
        }
        while(!rad.empty() && !dire.empty())
        {
            int r_idx=rad.front();
            int d_idx=dire.front();
            rad.pop_front();
            dire.pop_front();
            if(r_idx<d_idx)
            {
                rad.push_back(r_idx+n);
            }
            else
            {
                dire.push_back(d_idx+n);
            }
        }
        return rad.empty() ? "Dire" : "Radiant";
    }
};