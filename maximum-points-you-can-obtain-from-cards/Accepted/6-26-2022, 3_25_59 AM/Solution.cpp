// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        if(k==0)
            return 0;
        if(n==k)
        {
            int sum=0;
            for(int i=0;i<n;i++)
                sum+=cardPoints[i];
            return sum;
        }
        int total=0;
        for(int i=0;i<n;i++)
            total+=cardPoints[i];
        int sum=0;
        int a=n-k;
        for(int i=0;i<a;i++)
            sum+=cardPoints[i];
        int win_sum=sum;
        for(int i=a;i<n;i++)
        {
            win_sum-=cardPoints[i-a];
            win_sum+=cardPoints[i];
            sum=min(sum,win_sum);
        }
        
        return total-sum;
        
    }
};