// https://leetcode.com/problems/concatenation-of-array

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        nums.resize(2*n);
        for(int i = n; i<2*n;i++){
            nums[i]=nums[count++];
        }
        return nums;
    }
};