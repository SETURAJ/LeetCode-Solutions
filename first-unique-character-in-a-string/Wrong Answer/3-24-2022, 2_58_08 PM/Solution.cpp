// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>umap;
        int n =s.length();
        for(int i=0;i<n;i++)
        {
            umap[s[i]]++;
        }
        unordered_map<char,int>::iterator itr;
        char ch;
        bool flag=false;
        for(itr=umap.begin();itr!=umap.end();itr++)
        {
            if(itr->second ==1)
            {
                ch=itr->first;
                flag=true;
            }
        }
        if(flag)
        {
            for(int i=0;i<n;i++)
            {
                if(ch==s[i])
                    return i;
            }
        }
        return -1;
        
    }
};