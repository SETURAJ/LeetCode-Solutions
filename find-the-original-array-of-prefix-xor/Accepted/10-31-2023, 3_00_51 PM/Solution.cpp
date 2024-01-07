// https://leetcode.com/problems/find-the-original-array-of-prefix-xor

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int>arr(n,0);
        arr[0]=pref[0];
        if(pref.size()<=1)
            return pref;
        for(int i=1;i<n;i++)
            arr[i] = pref[i-1] ^ pref[i];
        return arr;
    }
};