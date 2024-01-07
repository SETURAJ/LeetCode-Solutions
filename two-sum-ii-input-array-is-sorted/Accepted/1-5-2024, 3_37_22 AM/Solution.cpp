// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n =numbers.size();
        int left=0;
        int right=n-1;
        vector<int>res;
        while(left<right)
        {
            if( (numbers[left]+numbers[right]) == target)
            {
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if((numbers[left]+numbers[right]) < target)
                left++;
            else
                right--;
        }
        return res;
    }
};