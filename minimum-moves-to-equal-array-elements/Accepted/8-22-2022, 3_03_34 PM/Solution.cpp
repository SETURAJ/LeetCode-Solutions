// https://leetcode.com/problems/minimum-moves-to-equal-array-elements

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        for(auto n:nums)
            mini=min(mini,n);
        int cnt=0;
        for(auto n:nums)
            cnt+=n-mini;
        return cnt;
    }
};