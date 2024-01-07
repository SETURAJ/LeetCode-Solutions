// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> ans(rowIndex+1,0);
         ans[0]=1;
        for(int i=0;i<rowIndex;i++)
        {
            int prev=ans[0];
            for(int j=1;j<i+1;j++)
            {
                int s=prev+ans[j];
                prev=ans[j];
                ans[j]=s;
            }
            ans[i+1]=1;
        }
        return ans;
    }
};