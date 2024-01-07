// https://leetcode.com/problems/count-nice-pairs-in-an-array

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> umap;
        if(nums.size()==1)
            return 0;
        int res = 0;
        int MOD = 1e9+7;
        for(int i=0;i<nums.size();i++)
        {
            int sum = nums[i] - rev(nums[i]);
            if(umap.find(sum)==umap.end())
            {
                umap[sum]++;
            }
            else
            {
                res += (umap[sum]%MOD);
                umap[sum]++;
            }
        }
        return res;
    }
    
    int rev(int number)
    {
        int revv=0,remainder;
        while(number != 0)
        {
            remainder = number%10;
            revv = revv*10 + remainder;
            number /= 10;
        }
        return revv;
    }
};