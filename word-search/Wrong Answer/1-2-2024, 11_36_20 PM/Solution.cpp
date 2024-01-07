// https://leetcode.com/problems/word-search

class Solution {
public:
    
    bool dfs(int i,int j,int m,int n,vector<vector<char>>&board,string word,int ind)
    {
        if(ind >= word.length())
            return true;
        if(i<0 || i>=m || j<0 || j>=n|| board[i][j]!=word[ind])
            return false;
        char c = board[i][j];
        board[i][j]='*';
        return dfs(i+1,j,m,n,board,word,ind+1) || dfs(i,j+1,m,n,board,word,ind+1) || 
            dfs(i-1,j,m,n,board,word,ind+1) ||  dfs(i,j-1,m,n,board,word,ind+1);
        board[i][j] = c;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(dfs(i,j,m,n,board,word,0))
                    return true;
        }
        return false;
    }
};