// https://leetcode.com/problems/uncrossed-lines

class Solution {
public:

    int func(int i,int j,vector<int>&nums1,vector<int>&nums2)
    {
        if(i==nums1.size() || j==nums2.size())
            return 0;
        int count=0;
        if(nums1[i]==nums2[j])
            count=1+func(i+1,j+1,nums1,nums2);
        else
            count+=max(func(i+1,j,nums1,nums2),func(i,j+1,nums1,nums2));
        return count;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return func(0,0,nums1,nums2);
    }
};