// https://leetcode.com/problems/plus-one

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size(),total=0,p=digits.size();
        for(int i=0;i<n;i++)
        {
            total+=digits[i]*pow(10,p-1);
            p--;
        }
        total++;
        vector<int>res;
        while(total>=10)
        {
            int rem=total%10;
            res.push_back(rem);
            total/=10;
        }
        res.push_back(total);
        reverse(res.begin(),res.end());
        return res;
    }
};