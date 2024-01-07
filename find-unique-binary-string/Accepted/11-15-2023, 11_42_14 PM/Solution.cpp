// https://leetcode.com/problems/find-unique-binary-string

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        for(int i=0;i<nums.size();i++)
        {
            char cur = nums[i][i];
            //cout<<cur<<endl;
            if(cur == '0')
                res+="1";
            else
                res+="0";
        }
        return res;
         
    }
};