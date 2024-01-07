// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        if(garbage.size()==1)
            return garbage[0].length();
        vector<int>prefixsum(travel.size()+1,0);
        prefixsum[1] = travel[0];
        for(int i=1;i<travel.size();i++)
            prefixsum[i+1] = prefixsum[i] + travel[i];
        unordered_map<char,int>umap;
        int finalg=-1,finalp=-1,finalm=-1;
        umap['P'] = 0;
        umap['M'] = 0;
        umap['G'] = 0;
         for(int i=0;i<garbage.size();i++)
        {
            for(auto c:garbage[i])
            {
                umap[c]++;
                if(c=='G')
                    finalg = i;
                if(c=='P')
                    finalp=i;
                if(c=='M')
                    finalm=i;
            }
        }
        int res = 0;
        if(finalg!=-1)
            res+=prefixsum[finalg];
        if(finalp!=-1)
            res+=prefixsum[finalp];
        if(finalm!=-1)
            res+=prefixsum[finalm];
        res = res + umap['P'] + umap['G'] + umap['M'];
        return res;
    }
};