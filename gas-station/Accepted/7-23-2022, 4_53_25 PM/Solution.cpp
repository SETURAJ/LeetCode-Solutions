// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_surp=0;
        int surp=0;
        int start=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            total_surp+=gas[i]-cost[i];
            surp+=gas[i]-cost[i];
            if(surp<0)
            {
                surp=0;
                start=i+1;
            }
        }
        return (total_surp<0)? -1:start;
    }
};