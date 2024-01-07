// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        int num1=-1,num2=-1,c1=0,c2=0;
        for(auto num:nums)
        {
            if(num1==num)
                c1++;
            else if(num2==num)
                c2++;
            else if(c1==0)
            {
                num1=num;
                c1=1;
            }
            else if(c2==0)
            {
                num2=num;
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        if(c1>n/3)
            res.push_back(num1);
        if(c2>n/3)
            res.push_back(num2);
        return res;
    }
};