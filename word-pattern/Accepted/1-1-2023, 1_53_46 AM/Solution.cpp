// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        string word;
        stringstream w(s);
        while(w>>word)
            v.push_back(word);
        set<string>S;
        if(v.size()!=pattern.size())
            return false;
        unordered_map<char,string>m;
        for(int i=0;i<pattern.size();i++)
        {
            char ch=pattern[i];
            if(m.find(ch)!=m.end())
            {
                if(m[ch]!=v[i])
                    return false;
            }
        else
        {
            if(S.count(v[i])>0)
                return false;
            m[ch]=v[i];
            S.insert(v[i]);
        }
    }
        return true;
    }
    
};