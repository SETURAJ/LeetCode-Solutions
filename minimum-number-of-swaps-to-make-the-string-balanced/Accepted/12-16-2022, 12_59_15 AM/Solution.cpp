// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(!st.empty() && (st.top()=='[' && s[i]==']'))
                st.pop();
            else
                st.push(s[i]);
        }
        int res=st.size()/2;
        if(res%2==0)
            return res/2;
        return (res+1)/2;
    }
};