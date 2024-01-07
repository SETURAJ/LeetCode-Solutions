// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber)
        {
            columnNumber--;
            char temp='A'+columnNumber%26;
            columnNumber/=26;
            res+=temp;
        }
        return res;
        
    }
};