// https://leetcode.com/problems/remove-stones-to-minimize-the-total

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int res=0;
        for(auto i:piles)
        {
            pq.push(i);
            res+=i;
        }
        while(k--)
        {
            int a=pq.top();
        
            int b=0;
            if(a%2==0)
            {
                b=(a/2);
                res-=b;
            }
            else
            {
                b=((a+1)/2);
                res-=b;
                res+=1;
            }
            pq.pop();
            pq.push(b);
        }
        return res;
    }
};