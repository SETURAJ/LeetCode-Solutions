// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    
    const vector<string>pho={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string>res;
        res.push_back("");
        for(auto digit:digits)
        {
            vector<string>tmp;
            for(auto can:pho[digit-'0'])
            {
                for(auto s:res)
                {
                    tmp.push_back(s+can);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};