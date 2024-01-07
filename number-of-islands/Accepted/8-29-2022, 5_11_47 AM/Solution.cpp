// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0)
            return 0;
        int res=0;
        stack<pair<int,int>>st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    st.push(make_pair(i,j));
                    while(!st.empty())
                    {
                        int x=st.top().first;
                        int y=st.top().second;
                        st.pop();
                        grid[x][y]='0';
                        if(y+1<n && grid[x][y+1]=='1')
                            st.push(make_pair(x,y+1));
                        if(x+1<m && grid[x+1][y]=='1')
                            st.push(make_pair(x+1,y));
                        if(y-1>=0 && grid[x][y-1]=='1')
                            st.push(make_pair(x,y-1));
                        if(x-1>=0 && grid[x-1][y]=='1')
                            st.push(make_pair(x-1,y));
                    }
                }
            }
        }
        return res;
        
    }
};