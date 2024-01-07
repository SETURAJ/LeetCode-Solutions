// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        int a=stoi(num1);
        int b=stoi(num2);
        int c=a*b;
        string res=to_string(c);
        return res;
    }
};