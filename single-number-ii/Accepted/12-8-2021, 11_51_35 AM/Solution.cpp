// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        unordered_map<int,int>::iterator it;
        int ans;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second==1)
                 ans=it->first;
        }
        return ans;
    }
};