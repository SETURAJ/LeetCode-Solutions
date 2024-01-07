// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int i=n-1;
        while(i>=0)
        {
            digits[i]++;
            if(digits[i]>=10)
            {
                digits[i]=digits[i]%10;
                i--;
            }
            else
                return digits;
        }
        if(i==-1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};