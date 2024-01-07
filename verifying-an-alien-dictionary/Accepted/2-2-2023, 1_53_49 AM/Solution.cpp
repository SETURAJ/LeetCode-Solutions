// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    std::vector<int> ordermap=std::vector<int>(26);

    bool compare(string s1,string s2)
    {
        int j=0;
        while(j<s1.length() && j<s2.length())
        {
            if(s1[j]==s2[j])
                j++;
            else if(ordermap[s1[j]-'a']>ordermap[s2[j]-'a'])
                return true;
            else return false;
        }
        if(s1.length()<s2.length())
            return false;
        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<order.length();i++)
            ordermap[order[i]-'a']=i;
        for(int i=1;i<words.size();i++)
        {
            if(!compare(words[i],words[i-1]))
                return false;
        }
        return true;
    }
};