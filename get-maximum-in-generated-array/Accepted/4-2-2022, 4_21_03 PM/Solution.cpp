// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<2)
            return n;
        vector<int>arr(n+1);
        int res=1;
        arr[0]=0,arr[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
                arr[i]=arr[i/2];
            else
                arr[i]=arr[i/2]+arr[i/2+1];
            res=max(res,arr[i]);
        }
        return res;
    }
};