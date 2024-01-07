// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

class Solution {
public:
    int countOdds(int low, int high) {
        int res=0;
        if(low%2==1)
            res++;
        if(high%2==1)
            res++;
        res+=((high-low)/2);
        if(low%2==1 && high%2==1)
            res--;
        return res;
    }
};