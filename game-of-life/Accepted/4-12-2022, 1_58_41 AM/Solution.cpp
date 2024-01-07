// https://leetcode.com/problems/game-of-life

class Solution {
public:
    
    int getLive(vector<vector<int>>&board,int i,int j,int m,int n)
    {
        int live=0;
        if(i>0)
        {
            if(board[i-1][j]==1 || board[i-1][j]==3)
                live++;
        }
        if(j>0)
        {
            if(board[i][j-1]==1 || board[i][j-1]==3)
                live++;
        }
        if(i<m-1)
        {
            if(board[i+1][j]==1 || board[i+1][j]==3)
                live++;
        }
        if(j<n-1)
        {
            if(board[i][j+1]==1 || board[i][j+1]==3)
                live++;
        }
        if(i>0 && j>0)
        {
            if(board[i-1][j-1]==1 || board[i-1][j-1]==3)
                live++;
        }
        
        if(i>0 && j<n-1)
        {
            if(board[i-1][j+1]==1 || board[i-1][j+1]==3)
                live++;
        }
        
        if(i<m-1 && j>0)
        {
            if(board[i+1][j-1]==1 || board[i+1][j-1]==3)
                live++;
        }
        
        if(i<m-1 && j<n-1)
        {
            if(board[i+1][j+1]==1 || board[i+1][j+1]==3)
                live++;
        }
        return live;
        
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ln=getLive(board,i,j,m,n);
                if(board[i][j]==0)
                {
                    if(ln==3)
                        board[i][j]=2;
                }
                else if(board[i][j]==1)
                {
                    if(ln<2 || ln>3)
                        board[i][j]=3;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==2)
                    board[i][j]=1;
                else if(board[i][j]==3)
                    board[i][j]=0;
            }
        }
    }
};