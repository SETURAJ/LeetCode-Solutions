// https://leetcode.com/problems/bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.length();
        int buf=0,cow=0;
        unordered_map<char,int>umap;
        for(int i=0;i<n;i++)
            umap[secret[i]]++;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                buf++;
            else
            {
                if(umap.find(guess[i])!=umap.end())
                {
                    cow++;
                    umap[guess[i]]--;
                }
            }
        }
        string res=to_string(buf)+"A"+to_string(cow)+"B";
        return res;
    }
};