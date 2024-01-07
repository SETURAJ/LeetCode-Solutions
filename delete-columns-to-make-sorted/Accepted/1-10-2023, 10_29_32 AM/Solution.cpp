// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res=0;
        int r=strs.size();
        int c=strs[0].size();
        for(int i=0;i<c;i++)
        {   
            for(int j=0;j<r-1;j++)
            {
                if(strs[j][i] > strs[j+1][i])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};