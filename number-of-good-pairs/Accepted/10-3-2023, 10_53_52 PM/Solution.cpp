// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>counts;
        int res=0;
        for(int n:nums)
        {
            res+=counts[n];
            counts[n]++;
        }
        return res;
    }
};