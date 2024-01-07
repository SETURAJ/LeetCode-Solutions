// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(int num : left)
            res = max(res,num);
        for(int num : right)
            res = max(res,n-num);
        return res;
    }
};