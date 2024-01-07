// https://leetcode.com/problems/roman-to-integer

class Solution {
public:
    int romanToInt(string s) {
        if(s.empty())
            return 0;
        unordered_map<char,int>umap={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'M',1000}
        };
        int num=0;
        int n=s.length();
        for(int i=0;i<n-1;i++)
        {
            if(umap[s[i]]<umap[s[i+1]])
                num-=umap[s[i]];
            else
                num+=umap[s[i]];
        }
        num+=umap[s.back()];
        return num;
    }
};