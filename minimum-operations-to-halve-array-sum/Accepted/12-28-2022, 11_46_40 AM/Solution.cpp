// https://leetcode.com/problems/minimum-operations-to-halve-array-sum

class Solution {
public:
    int halveArray(vector<int>& nums) {
        double count=0,sum=0;
        priority_queue<double>pq;
        for(auto i:nums)
        {
            pq.push(i);
            sum+=i;
        }
        double total=0;
        while(sum - total > (sum/2))
        {
            double a=pq.top();
            pq.pop();
            total += a/2;
            pq.push(a/2);
            count++;
        }
        return count;
    }
};