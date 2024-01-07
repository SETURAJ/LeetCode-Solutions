// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator it1,it2;
        it1=nums1.begin()+m;
        it2=nums1.end();
        nums1.erase(it1,it2);
        it1=nums2.begin()+n;
        it2=nums2.end();
        nums2.erase(it1,it2);
        int i=0,j=0;
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
                i++;
            else if(nums1[i]==nums2[j])
            {
                swap(nums1[i],nums2[j]);
                    i++;
            }
            else if(nums2[j]<nums1[i])
            {
                swap(nums1[i],nums2[j]);
                j++;
                i++;
            }
        }
        
        for(int i=0;i<n;i++)
            nums1.push_back(nums2[i]);
        sort(nums1.begin(),nums1.end());
    }
};