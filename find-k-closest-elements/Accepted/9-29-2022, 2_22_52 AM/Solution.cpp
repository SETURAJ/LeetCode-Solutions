// https://leetcode.com/problems/find-k-closest-elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int l=0,r=n-k;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(arr[mid]==arr[mid+k])
            {
                if(x>arr[mid])
                    l=mid+1;
                else
                    r=mid;
            }
            else if(abs(x-arr[mid])<=abs(x-arr[mid+k]))
                r=mid;
            else
                l=mid+1;
        }
        return vector<int>(arr.begin()+l,arr.begin()+l+k);
    }
};