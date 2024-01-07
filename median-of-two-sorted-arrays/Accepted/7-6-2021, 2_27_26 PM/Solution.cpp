// https://leetcode.com/problems/median-of-two-sorted-arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        int i=0,j=0,k=0;
        vector<int>arr(nums1.size()+nums2.size());
        while(k<(l1+l2))
        {
            if(i<l1 && j<l2)
            {
                if(nums1[i]<nums2[j])
                {    
                    arr[k]=nums1[i];
                    i++;
                }
                else
                {
                    arr[k]=nums2[j];
                    j++;
                }
            }
            else if(i<l1)
            {
                arr[k]=nums1[i];
                i++;
            }
            else if(j<l2)
            {
                arr[k]=nums2[j];
                j++;
            }
            else 
            {
                break;
            }
            k++;
        }
        
        double median=0;
        int l=l1+l2;
        if((l%2==0))
        {
            median=(arr[l/2]+arr[l/2-1])/2.0;
        }
        else
            median=arr[l/2];
        
        return median;
    }
};