// https://leetcode.com/problems/happy-number

class Solution {
public:
    
    int findsquare(int n)
    {
        int sum=0,temp;
        while(n)
        {
            temp=n%10;
            sum+=temp*temp;
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow,fast;
        slow=fast=n;
        do
        {
            slow=findsquare(slow);
            fast=findsquare(fast);
            fast=findsquare(fast);
                
        }while(slow!=fast);
            
        if(slow==1)
            return 1;
        else
            return 0;
    }
};