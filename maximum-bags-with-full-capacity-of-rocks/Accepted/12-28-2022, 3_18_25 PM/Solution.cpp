// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int>rem(n);
        for(int i=0;i<n;i++)
            rem[i]=capacity[i]-rocks[i];
        int res=0;
        sort(rem.begin(),rem.end());
        for(int i=0;i<n;i++)
        {
            if(rem[i]>additionalRocks)
                break;
            else
            {
                additionalRocks-=rem[i];
                rem[i]=0;
            }
        }
        for(auto i:rem)
        {
            if(i==0)
                res++;
        }
        return res;
    }
};