// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       //Boyer-Moore Voting Algorithm
        int count=0;
        int candidate;
        for(int num:nums)
        {
            if(count==0)
                candidate=num;
            count+=(num==candidate)?1:-1;
        }
        return candidate;
    }
};