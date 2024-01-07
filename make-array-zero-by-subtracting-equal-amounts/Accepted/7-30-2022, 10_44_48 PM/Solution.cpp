// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
       sort(nums.begin(),nums.end());
        unordered_set<int> s;
    for (int i=0; i<n; i++)
    {
        
        if (!s.count(nums[i]) && nums[i]!=0)  
        {
            s.insert(nums[i]);
        }
    }
        return s.size();
    }
};