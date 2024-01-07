// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int sz = floor(n/3);
        vector<int>res;
        int num1=1e9,num2=1e9,c1=0,c2=0;
        for(auto num:nums)
        {
            if(num1==num)
                c1++;
            else if(num2 == num)
                c2++;
            else if(c1==0)
            {
                num1=num;
                c1++;
            }
            else if(c2==0)
            {
                num2=num;
                c2++;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto num:nums)
        {
            if(num1==num)
                c1++;
            if(num2==num)
                c2++;
        }
        if(c1>sz)
            res.push_back(num1);
        if(c2>sz)
            res.push_back(num2);
        return res;
        
    }
};