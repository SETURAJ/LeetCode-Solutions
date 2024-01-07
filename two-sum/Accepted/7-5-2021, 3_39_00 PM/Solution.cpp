// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        unordered_map<int,int>hash;
        vector<int>result;
        for(int i=0;i<num.size();i++)
        {
            int number_to_find=target-num[i];
            if(hash.find(number_to_find)!=hash.end())
            {
                result.push_back(hash[number_to_find]);
                result.push_back(i);
            }
            hash[num[i]]=i;
        }
        return result;
    }
};