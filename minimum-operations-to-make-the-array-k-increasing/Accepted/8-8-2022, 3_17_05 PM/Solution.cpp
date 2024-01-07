// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing

class Solution {
public:
    
    int lis(vector<int>&nums)
    {
        vector<int>sub;
        for(auto n:nums)
        {
            if(sub.empty() || sub[sub.size()-1]<=n)
                sub.push_back(n);
            else
            {
                auto it=upper_bound(sub.begin(),sub.end(),n);
                *it=n;
            }
        }
        return sub.size();
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        for(int i=0;i<k;++i)
        {
            vector<int>temp;
            for(int j=i;j<n;j+=k)
                temp.push_back(arr[j]);
            ans+=temp.size()-lis(temp);
        }
        return ans;
    }
};