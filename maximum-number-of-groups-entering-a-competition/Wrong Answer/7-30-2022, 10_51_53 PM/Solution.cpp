// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        return (n+1)/2;
    }
};