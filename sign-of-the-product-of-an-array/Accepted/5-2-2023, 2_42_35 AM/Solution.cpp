// https://leetcode.com/problems/sign-of-the-product-of-an-array

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res=1;
        for(auto i:nums)
        {
            if(i==0)
                return 0;
            else if(i>0)
                res*=1;
            else
                res*=-1;
        }
        return res;
    }
};