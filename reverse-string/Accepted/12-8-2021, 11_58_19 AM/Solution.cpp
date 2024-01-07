// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==1)
            return;
        int left=0,right=s.size()-1;
        while(left<right)
        {
            swap(s[left],s[right]);
            left++;
            right--;
            
        }
        for(int i=0;i<s.size();i++)
            cout<<s[i]<<" ";
    }
};