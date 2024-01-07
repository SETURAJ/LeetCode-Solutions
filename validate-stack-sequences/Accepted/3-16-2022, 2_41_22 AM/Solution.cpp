// https://leetcode.com/problems/validate-stack-sequences

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int count=0;
        for(int x:pushed)
        {
            st.push(x);
            while(st.size() && st.top()==popped[count])
            {
                st.pop();
                count++;
            }
        }
        return st.size()==0;
    }
};