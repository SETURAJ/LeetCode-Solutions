// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        for(auto n:nums)
            count[n]++;
        int res = 0;
        for(auto x:count)
        {
            if(x.second == 1)
                return -1;
            if(x.second % 3 ==0)
                res+=(x.second/3);
            else
                res +=(x.second/3+1);
        }
        return res;
    }
};