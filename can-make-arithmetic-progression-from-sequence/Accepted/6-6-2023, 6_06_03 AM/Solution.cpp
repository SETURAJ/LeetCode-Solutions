// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()<=2)
            return true;
        int diff= arr[1]-arr[0];
        for(int i=2;i<arr.size();i++)
        {
            if(arr[i]-arr[i-1]!=diff)
                return false;
        }
        return true;
    }
};