// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        vector<int> goal(26),cur(26);
        for(auto c:s1)
            goal[c-'a']++;
        for(int i=0;i<s2.length();i++)
        {
            cur[s2[i]-'a']++;
            if(i>=s1.length())
                cur[s2[i-s1.length()]-'a']--;
            if(goal==cur)
                return true;
        }
        return false;
    }
};