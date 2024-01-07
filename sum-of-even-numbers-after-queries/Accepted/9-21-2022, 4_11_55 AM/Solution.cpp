// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>res;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                sum+=nums[i];
        }
        for(auto q:queries)
        {
            if(nums[q[1]]%2==0)
                sum-=nums[q[1]];
            nums[q[1]]+=q[0];
            if(nums[q[1]]%2==0)
                sum+=nums[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};