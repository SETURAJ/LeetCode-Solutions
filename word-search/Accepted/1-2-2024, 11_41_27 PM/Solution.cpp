// https://leetcode.com/problems/word-search

class Solution {
public:
    
    bool dfs(int i,int j,int m,int n,vector<vector<char>>&board,string word)
    {
        if(!word.length())
            return true;
        if(i<0 || i>=m || j<0 || j>=n|| board[i][j]!=word[0])
            return false;
        char c = board[i][j];
        board[i][j]='*';
        string s = word.substr(1);
        bool res = dfs(i+1,j,m,n,board,s) || dfs(i,j+1,m,n,board,s) || dfs(i-1,j,m,n,board,s) ||dfs(i,j-1,m,n,board,s);
        board[i][j] = c;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        string s = word;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(dfs(i,j,m,n,board,s))
                    return true;
        }
        return false;
    }
};