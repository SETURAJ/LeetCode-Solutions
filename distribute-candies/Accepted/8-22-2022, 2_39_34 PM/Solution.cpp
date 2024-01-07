// https://leetcode.com/problems/distribute-candies

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,int>umap;
        for(auto i:candyType)
            umap[i]++;
        return min(umap.size(),candyType.size()/2);
    }
};