// https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy-fy);
        return x<=t && y<=t;
        
    }
};