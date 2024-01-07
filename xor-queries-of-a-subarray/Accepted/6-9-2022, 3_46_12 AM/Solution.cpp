// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pre(n);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]^arr[i];
        vector<int>res;
        for(auto const &q:queries)
        {
            int a=q[0];
            int b=q[1];
            if(a==b)
                res.push_back(arr[a]);
            else if(a==0)
                res.push_back(pre[b]); 
            else
            {
                int sol=pre[b]^pre[a-1];
                res.push_back(sol);
            }
        }
        return res;
    }
};