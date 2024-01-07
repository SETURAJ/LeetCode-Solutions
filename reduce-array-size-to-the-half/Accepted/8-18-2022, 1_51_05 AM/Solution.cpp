// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
            umap[arr[i]]++;
        int res=0,l=n;
        vector<int>keys;
        for(auto& it:umap)
            keys.push_back(it.second);
        sort(keys.begin(),keys.end(),greater<int>());
        int trace=0;
        while(l>n/2)
        {
            res++;
            l-=keys[trace];
            trace++;
        }
        return res;
    }
};