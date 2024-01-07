// https://leetcode.com/problems/contains-duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>h;
        for(int i=0;i<nums.size();i++)
        {    
            h[nums[i]]++;
            if(h[nums[i]]>=2)
                return true;
        }
        return false;
    }
};