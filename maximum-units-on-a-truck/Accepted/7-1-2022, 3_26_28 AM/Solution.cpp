// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    
    static bool compare(const vector<int>&v1,const vector<int>&v2)
    {
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int ans = 0;
        for (auto& b : boxTypes) {
            int count = min(b[0], truckSize);
            ans += count * b[1], truckSize -= count;
			if (!truckSize) return ans;
        }
        return ans;
    }
};