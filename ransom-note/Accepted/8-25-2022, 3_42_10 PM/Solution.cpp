// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>vec(26,0);
        for(int i=0;i<magazine.size();i++)
            vec[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.size();i++)
        {
            if(vec[ransomNote[i]-'a']==0)
                return false;
            vec[ransomNote[i]-'a']--;
        }
        return true;
        
    }
};