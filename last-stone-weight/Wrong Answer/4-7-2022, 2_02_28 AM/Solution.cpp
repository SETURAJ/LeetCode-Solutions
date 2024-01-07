// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1)
            return stones[0];
        sort(stones.begin(),stones.end());
        if(n==2)
            return abs(stones[0]-stones[1]);
        while(stones.size()>1)
        {
            int n=stones.size();
            if(stones[n-1]==stones[n-2])
            {
                stones.pop_back();
                stones.pop_back();
            }
            else
            {
                int a=abs(stones[n-1]-stones[n-2]);
                stones.pop_back();
                stones.back()=a;
            }
        }
        if(stones.size()==1)
            return stones[0];
        return 0;
        
    }
};