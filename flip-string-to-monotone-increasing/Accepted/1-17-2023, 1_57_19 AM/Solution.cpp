// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res=0,cnt_one=0;
        for(auto i:s)
        {
            if(i == '1')
                cnt_one++;
            else
            {
                res++;
                res=min(res,cnt_one);
            }
        }
        return res;
    }
};