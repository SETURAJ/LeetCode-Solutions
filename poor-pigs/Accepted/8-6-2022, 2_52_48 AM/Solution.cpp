// https://leetcode.com/problems/poor-pigs

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T=minutesToTest/minutesToDie+1;
        int n=buckets;
        return ceil((log(n))/(log(T)));
    }
};