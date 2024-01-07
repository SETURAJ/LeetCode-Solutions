// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int>mp;
        int res=0;
        for(int i:nums1)
        {
            for(int j:nums2)
            {
                mp[i+j]++;
            }
        }
        for(int i:nums3)
        {
            for(int j:nums4)
            {
                res+=mp[-(i+j)];
            }
        }
        return res;
    }
};