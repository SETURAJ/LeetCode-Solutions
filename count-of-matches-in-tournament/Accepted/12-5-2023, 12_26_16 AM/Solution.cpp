// https://leetcode.com/problems/count-of-matches-in-tournament

class Solution {
public:
    int numberOfMatches(int n) {
        int res=0;
        while(n!=1)
        {
            if(n%2==0)
            {
                res+=(n/2);
                n/=2;
            }
            else
            {
                res+=(n/2)+1;
                n/=2;
            }
        }
        return res;
    }
};