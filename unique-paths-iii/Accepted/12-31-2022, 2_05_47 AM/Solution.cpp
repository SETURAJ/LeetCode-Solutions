// https://leetcode.com/problems/unique-paths-iii

class Solution {
public:
    int res=0;
    int sr=-1;
    int sc=-1;

    void find(vector<vector<int>>&grid,int row, int col,int count)
    {
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
            return;
        if(grid[row][col]==-1)
            return;
        if(grid[row][col]==2 && (count-1)==0)
        {
            res++;
            return;
        }
        if(grid[row][col]==2 && (count-1)!=0)
            return;
        grid[row][col]=-1;
        find(grid,row-1,col,count-1);
        find(grid,row+1,col,count-1);
        find(grid,row,col-1,count-1);
        find(grid,row,col+1,count-1);

        grid[row][col]=1;
    }

    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    count++;
                else if(grid[i][j]==2)
                    count++;
                else if(grid[i][j]==1)
                {
                    count++;
                    sr=i;
                    sc=j;
                }
            }
        }
        int i=sr;
        int j=sc;
        find(grid,i,j,count);
        return res;
    }
};