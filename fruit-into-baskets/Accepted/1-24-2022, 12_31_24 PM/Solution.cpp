// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<=2)
            return fruits.size();
        int left=0;
        unordered_map<int,int>umap;
        int ans=0;
        for(int end=0;end<fruits.size();end++)
        {
            umap[fruits[end]]++;
            while(umap.size()>2)
            {
                umap[fruits[left]]--;
                if(umap[fruits[left]]==0)
                    umap.erase(fruits[left]);
                left++;
            }
            ans=max(ans,end-left+1);
        }
        return ans;
    }
};