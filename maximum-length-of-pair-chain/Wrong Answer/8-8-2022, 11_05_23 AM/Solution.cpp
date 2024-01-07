// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
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