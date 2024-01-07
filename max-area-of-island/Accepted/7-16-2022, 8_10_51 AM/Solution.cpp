// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int find(vector<vector<int>>&grid,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n ||j>=m || !grid[i][j])
            return 0;
        grid[i][j]=0;
        return 1+find(grid,i-1,j,n,m)+find(grid,i+1,j,n,m)+find(grid,i,j-1,n,m)+find(grid,i,j+1,n,m);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    ans=max(ans,find(grid,i,j,n,m));
            }
        }
        return ans;
    }
};