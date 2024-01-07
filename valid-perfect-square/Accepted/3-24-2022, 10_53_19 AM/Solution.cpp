// https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int low=1;
        long long int high=num;
        while(low<high)
        {
            long long  mid=(low+high)/2;
            if(mid*mid < num)
                low=mid+1;
            else if(mid*mid >num)
                high=mid-1;
            else
            {
                low=mid;
                break;
            }
        }
        return (num % low ==0 && low==num/low);
    }
};