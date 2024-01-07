// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if(arr.size()<3)
            return 0;
        
        int n=arr.size();
        
        int ans=0,i=0;
        while(i<n)
        {
            int start=i;
            while(i<n-1 && arr[i+1]>arr[i])
                i++;
            if(i==start)
            {
                i++;
                continue;
            }
            int peak=i;
            while(i<n-1 && arr[i+1]<arr[i])
                i++;
            if(i==peak)
            {    i++;
                continue;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};