// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.length()==0)
            return 0;
        stack<char>st;
        int res=0;
        for(char c:s)
        {
            if(c=='(')
                st.push(c);
            else
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    res++;
            }
        }
        return res+st.size();
    }
};