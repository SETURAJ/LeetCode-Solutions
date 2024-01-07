// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1] || a[1]==b[1] && a[0]<b[0];
    }
        
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int curr=INT_MIN,res=0;
        for(auto const& p:pairs)
        {
            if(curr<p[0])
            {
                curr=p[1];
                res++;
            }
        }
      return res;
    }
};