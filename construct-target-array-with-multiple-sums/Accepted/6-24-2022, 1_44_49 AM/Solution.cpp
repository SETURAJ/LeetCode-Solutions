// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long int sum=0;
        priority_queue<long long int>pq;
        for(long long int num:target)
        {
            sum+=num;
            pq.push(num);
        }
        while(pq.top()!=1)
        {
           long long int  num=pq.top();
            pq.pop();
            sum-=num;
            if(num<=sum || sum<1)
                return false;
            num%=sum;
            sum+=num;
            pq.push(num? num:sum);
        }
        return true;
    }
};