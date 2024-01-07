// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> Hash;
        int a,b;
        for(int i=0;i<nums.size();i++)
        {
            int num_find=target-nums[i];
            if(Hash.find(num_find)!=Hash.end())
            {
                a=i;
                b=Hash[num_find];
            }
            Hash[nums[i]]=i;
        }
        return {a,b};
    }
};