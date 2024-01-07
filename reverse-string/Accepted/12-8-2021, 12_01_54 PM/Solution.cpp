// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void rev(int left,int right,vector<char>&s)
    {
        if(left>=right)
            return;
        swap(s[left],s[right]);
        rev(left+1,right-1,s);
    }
    void reverseString(vector<char>& s) {
       rev(0,s.size()-1,s);
    }
};