// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++)
            umap[(arr[i]%k+k)%k]++;
        for(int i=0;i<n;i++)
        {
            int r=(k+arr[i]%k)%k;
            if(r==0)
            {
                if(umap[r]%2!=0)
                    return false;
            }
            else if(umap[r]!=umap[k-r])
                return false;
        }
        return true;
    }
};