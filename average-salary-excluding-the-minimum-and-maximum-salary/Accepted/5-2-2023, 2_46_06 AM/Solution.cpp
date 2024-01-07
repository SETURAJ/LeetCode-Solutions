// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

class Solution {
public:
    double average(vector<int>& salary) {
        double res=0;
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(auto i:salary)
        {
            mn=min(mn,i);
            mx=max(mx,i);
            res+=i;
        }
        res=res-mn-mx;
        return (res/((salary.size())-2));
    }
};