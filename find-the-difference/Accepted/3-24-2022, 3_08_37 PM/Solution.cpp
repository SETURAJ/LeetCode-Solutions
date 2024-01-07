// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length()==0)
            return t[0];
        char res;
        unordered_map<char,int>umap;
        for(auto &c:s)
            umap[c]++;
        int n=t.length();
        for(int i=0;i<n;i++)
        {
            umap[t[i]]--;
            if(umap[t[i]]==0)
                umap.erase(t[i]);
        }
        auto it=umap.begin();
       
        return  it->first;;
    }
};