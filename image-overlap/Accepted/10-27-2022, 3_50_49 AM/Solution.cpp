// https://leetcode.com/problems/image-overlap

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=img2.size();
        vector<pair<int,int>>v1;
        vector<pair<int,int>>v2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(img1[i][j]==1)
                    v1.push_back({i,j});
                if(img2[i][j]==1)
                    v2.push_back({i,j});
            }
        }
        int res=0;
        map<pair<int,int>,int>mp;
        for(auto i:v1)
        {
            for(auto j:v2)
            {
                int x=i.first-j.first;
                int y=i.second-j.second;
                mp[{x,y}]++;
                res=max(res,mp[{x,y}]);
            }
        }
        return res;
    }
};