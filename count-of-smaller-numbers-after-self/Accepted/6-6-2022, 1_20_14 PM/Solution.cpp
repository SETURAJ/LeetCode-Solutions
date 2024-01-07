// https://leetcode.com/problems/count-of-smaller-numbers-after-self

class Solution {
public:
    vector<int>sol;
    void merge(vector<pair<int,int>>&vec,int left,int mid,int right)
    {
        int i=left,j=mid+1;
        while(i<=mid && j<=right)
        {
            if(vec[i].first<=vec[j].first)
            {
                sol[vec[i].second]+=(j-mid-1);
                i++;
            }
            else
                j++;
        }
        while(i<=mid)
        {
            sol[vec[i].second]+=(j-mid-1);
            i++;
        }
        sort(vec.begin()+left,vec.begin()+right+1);
    }
    
    void mergesort(vector<pair<int,int>>&vec,int left,int right)
    {
        if(left>=right)
            return;
        int mid=left+(right-left)/2;
        mergesort(vec,left,mid);
        mergesort(vec,mid+1,right);
        merge(vec,left,mid,right);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        sol.resize(n,0);
        vector<pair<int,int>>idx;
        for(int i=0;i<n;i++)
            idx.push_back({nums[i],i});
        mergesort(idx,0,n-1);
        return sol;
    }
};