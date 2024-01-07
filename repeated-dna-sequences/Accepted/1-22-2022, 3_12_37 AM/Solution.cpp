// https://leetcode.com/problems/repeated-dna-sequences

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<=9)
            return {};
        unordered_map<string,int>umap;
        string tmp="";
        for(int i=0;i<10;i++)
            tmp+=s[i];
        umap[tmp]++;
        for(int i=10;i<s.length();i++)
        {
            tmp+=s[i];
            tmp.erase(tmp.begin(),tmp.begin()+1);
            umap[tmp]++;
        }
        vector<string>ans;
        for(auto i:umap)
        {
            if(i.second>1)
                ans.push_back(i.first);
        }
        return ans;
    }
};