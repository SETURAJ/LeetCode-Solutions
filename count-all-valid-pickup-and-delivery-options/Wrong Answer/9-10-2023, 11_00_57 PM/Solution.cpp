// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countOrders(int n) {
        if( n== 1)
            return 1;
        if(n==2)
            return 6;
        long long int res=1;
        for(int i=2;i<=n;i++)
        {
            res = (res*(2*i-1)*i);
        }
        return res;
    }
};