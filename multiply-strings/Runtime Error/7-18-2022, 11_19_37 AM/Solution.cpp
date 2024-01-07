// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
        long long int a=stoi(num1);
        long long int b=stoi(num2);
        long long int c=a*b;
        string res=to_string(c);
        return res;
    }
};