// https://leetcode.com/problems/add-digits

class Solution {
public:
    
    int adddigit(int num)
    {
        int res=0;
        while(num)
        {
            int temp=num%10;
            res+=temp;
            num/=10;
        }
        return res;
    }
    
    int addDigits(int num) {
        int res=0;
        if(num<10)
            return num;
        while(num>9)
        {
            num=adddigit(num);
            if(num<10)
                res=num;
        }
        return res;
    }
};