// https://leetcode.com/problems/merge-sorted-array

class Solution {
public:
    
    void msa(vector<int>& nums1,  vector<int>& nums2, int m,int n)
    {
        int gap=ceil((float)(m+n)/2);
        while(gap>0)
        {
            int i=0,j=gap;
            while(j<(m+n))
            {
                if(j<m && nums1[i]>nums2[j])
                    swap(nums1[i],nums2[j]);
                else if(j>=m && i<m && nums1[i]>nums2[j-m])
                    swap(nums1[i],nums2[j-n]);
                else if(j>=m && i>=m && nums2[i-m]>nums2[j-m])
                    swap(nums2[i-m],nums2[j-m]);
                i++;
                j++;
            }
            if(gap==1)
                gap=0;
            else
                gap=ceil((float)gap/2);
        }
        for(int i=0;i<n;i++)
            nums1.push_back(nums2[i]);
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>::iterator it1,it2;
        it1=nums1.begin()+m;
        it2=nums1.end();
        nums1.erase(it1,it2);
        
        msa(nums1,nums2,m,n);
    }
};