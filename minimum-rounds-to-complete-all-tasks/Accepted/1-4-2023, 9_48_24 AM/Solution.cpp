// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>umap;
        int n=tasks.size();
        for(int i=0;i<n;i++)
        {
            umap[tasks[i]]++;
        }
        int res=0;
        for(auto t:umap)
        {
            int a=t.second;
            if(a==1)
                return -1;
            else if(a%3==0)
                res+=(a/3);
            else
            {
                res+=(a/3);
                res+=1;
            }
        }
        return res;
    }
};