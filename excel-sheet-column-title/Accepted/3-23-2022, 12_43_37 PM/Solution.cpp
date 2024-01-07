// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        char  temp;
        while(columnNumber)
        {
            columnNumber--;
            temp='A'+columnNumber%26;
            res+=temp;
            columnNumber/=26;
            
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};