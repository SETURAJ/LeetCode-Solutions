// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int res=0;
        int l=n.length();
        for(int i=0;i<l;i++)
        {
            char a=n[i];
            int b=a-'0';
            res=max(b,res);
        }
        return res;
    }
};