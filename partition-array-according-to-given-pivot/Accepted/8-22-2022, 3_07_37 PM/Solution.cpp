// https://leetcode.com/problems/partition-array-according-to-given-pivot

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>res;
        for(auto i:nums)
        {
            if(i<pivot)
                res.push_back(i);
        }
        for(auto i:nums)
        {
            if(i==pivot)
                res.push_back(i);
        }
        for(auto i:nums)
        {
            if(i>pivot)
                res.push_back(i);
        }
        return res;
    }
};