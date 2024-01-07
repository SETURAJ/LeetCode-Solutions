// https://leetcode.com/problems/sum-of-subarray-minimums

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<pair<int,int>>s_nle,s_ple;
        vector<int>left(arr.size()),right(arr.size());
        for(int i=0;i<arr.size();i++)
            left[i]=i+1;
        for(int i=0;i<arr.size();i++)
            right[i]=arr.size()-i;
        
        for(int i=0;i<arr.size();i++)
        {
            while(!s_ple.empty() && s_ple.top().first>arr[i])
                s_ple.pop();
            left[i]=s_ple.empty()?i+1:i-s_ple.top().second;
            s_ple.push({arr[i],i});
            
            while(!s_nle.empty() && s_nle.top().first>arr[i])
            {
                auto x=s_nle.top();
                s_nle.pop();
                right[x.second]=i-x.second;
            }
            s_nle.push({arr[i],i});
        }
        long long int ans=0, mod=1e9+7;
        for(int i=0;i<arr.size();i++)
            ans+=(arr[i]*left[i]*right[i])%mod;
        return ans;
    }
};