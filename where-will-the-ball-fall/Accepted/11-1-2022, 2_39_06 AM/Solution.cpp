// https://leetcode.com/problems/where-will-the-ball-fall

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int k=0;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            k=i;
            for(int j=0;j<m;j++)
            {
                if((k==0 && grid[j][k]==-1) || (k==n-1 && grid[j][k]==1))
                {
                    k=-1000;
                    break;
                }
                if(grid[j][k]==-1)
                {
                    if(grid[j][k-1]==-1)
                        k--;
                    else
                    {
                        k=-1000;
                        break;
                    }
                }
                if(grid[j][k]==1)
                {
                    if(grid[j][k+1]==1)
                        k++;
                    else
                    {
                        k=-1000;
                        break;
                    }
                }
            }
            if(k<0)
                res.push_back(-1);
            else
                res.push_back(k);
        }
        return res;
    }
};