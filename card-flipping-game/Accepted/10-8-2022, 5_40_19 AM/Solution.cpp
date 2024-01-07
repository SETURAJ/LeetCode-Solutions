// https://leetcode.com/problems/card-flipping-game

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int>uset;
        for(int i=0;i<fronts.size();i++)
        {
            if(fronts[i]==backs[i])
                uset.insert(fronts[i]);
        }
        int res=INT_MAX;
        for(auto i:fronts)
        {
            if(!uset.count(i))
                res=min(res,i);
        }
        for(auto i:backs)
        {
            if(!uset.count(i))
                res=min(res,i);
        }
        return res==INT_MAX?0:res;
    }
};