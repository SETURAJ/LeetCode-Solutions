// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& price) {
        int N=price.size();
        int K=2;
        vector<vector<int>>profit(3,vector<int>(N+1,0));
        for(int i=0;i<=K;i++)
            profit[i][0]=0;
        for(int i=0;i<=N;i++)
            profit[0][i]=0;
        
        for(int i=1;i<=K;i++)
        {
            for(int j=1;j<N;j++)
            {
                int max_so=INT_MIN;
                for(int m=0;m<j;m++)
                {
                    max_so=max(max_so,price[j]-price[m]+profit[i-1][m]);
                    profit[i][j]=max(max_so,profit[i][j-1]);
                }
            }
        }
        return profit[K][N-1];
    }
};