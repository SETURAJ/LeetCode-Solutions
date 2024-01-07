// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy-fy);
        if(max(x,y)==0 && t==1)
            return false;
        return max(x,y) <= t;
        
    }
};