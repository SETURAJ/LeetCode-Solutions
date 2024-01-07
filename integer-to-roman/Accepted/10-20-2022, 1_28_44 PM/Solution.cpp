// https://leetcode.com/problems/integer-to-roman

class Solution {
    private:
    vector<vector<string>>romans={{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, 
                                     {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, 
                                     {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, 
                                     {"M", "MM", "MMM"}};
public:
    string intToRoman(int num) {
        string res="";
        int i=-1;
        while(num)
        {
            int cur=num%10;
            i++;
            if(cur)
            {
                res.insert(0,romans[i][cur-1]);
            }
            num/=10;
            
        }
        return res;
    }
};