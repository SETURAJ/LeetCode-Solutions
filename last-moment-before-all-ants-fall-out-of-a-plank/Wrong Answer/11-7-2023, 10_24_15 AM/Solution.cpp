// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        if(left.size()==0 || right.size()==0)
            return n;
        int res = 0;
        for(int num : left)
            res = max(res,num);
        for(int num : right)
            res = max(res,n-num);
        return res;
    }
};