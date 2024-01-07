// https://leetcode.com/problems/number-of-equivalent-domino-pairs

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        map<vector<int>,int> m;
        int res=0;
        for(auto& d:dominoes){
            int i=min(d[0],d[1]),j=max(d[0],d[1]);
            m[{i,j}]++;
        }
        for(auto& k:m){
            if(k.second==1) continue;
            else res+=(k.second*(k.second-1))/2;
        }
        return res;
    }
};