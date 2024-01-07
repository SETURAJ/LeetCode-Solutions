// https://leetcode.com/problems/maximum-number-of-coins-you-can-get

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sz = piles.size();
        int n = sz/3;
        if(sz==3)
            return piles[1];
        int res = 0;
        for(int i=n;i<sz;i+=2)
            res+=piles[i];
        return res;
    }
};