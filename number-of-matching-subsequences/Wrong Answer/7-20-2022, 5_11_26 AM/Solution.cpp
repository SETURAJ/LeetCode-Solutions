// https://leetcode.com/problems/number-of-matching-subsequences

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,int>umap;
        unordered_map<char,int>track;
        for(int i=0;i<s.length();i++)
            umap[s[i]]++;
        track=umap;
        int n=words.size();
        int res=0;
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            bool flag=true;
            track=umap;
            int m=s.length();
            for(int j=0;j<m;j++)
            {
                if(track.find(s[j])!=track.end())
                    track[s[j]]--;
                else
                    flag=false;
            }
            if(flag)
                res++;
        }
        return res;
    }
};