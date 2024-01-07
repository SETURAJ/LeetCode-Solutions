// https://leetcode.com/problems/find-the-winner-of-an-array-game

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if(n==1)
            return arr[0];
        if(k==1)
            return max(arr[0],arr[1]);
        if(k>=n)
            return *max_element(arr.begin(),arr.end());
        bool flag = true;
        int res = arr[0],count = 0;
        for(int i = 1; i< n; i++)
        {
            if(res>arr[i])
                count++;
            else
            {
                res=arr[i];
                count = 1;
            }
            if(count == k )
                return res;
        }
        return res;
    }
};