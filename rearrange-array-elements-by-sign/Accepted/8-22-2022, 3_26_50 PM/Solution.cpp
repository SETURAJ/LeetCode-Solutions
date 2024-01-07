// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s=nums.size();
        vector<int>res(s);
        int pos=0,neg=1;
        for(auto n:nums)
        {
            if(n>0)
            {
                res[pos]=n;
                pos+=2;
            }
            else if(n<0)
            {
                res[neg]=n;
                neg+=2;
            }
        }
        return res;
    }
};