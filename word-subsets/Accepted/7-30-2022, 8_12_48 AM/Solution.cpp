// https://leetcode.com/problems/word-subsets

class Solution {
public:
    
    vector<int>countfreq(string& w)
    {
        vector<int>freq(26);
        for(auto &c:w)
            freq[c-'a']++;
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>maxFreq(26);
        vector<string>res;
        for(auto &w:words2)
        {
            vector<int>freq=countfreq(w);
            for(int i=0;i<26;i++)
                maxFreq[i]=max(freq[i],maxFreq[i]);
        }
        for(auto &w:words1)
        {
            vector<int>freq=countfreq(w);
            bool flag=true;
            for(int i=0;i<26;i++)
                if(freq[i]<maxFreq[i])
                    flag=false;
            if(flag)
                res.push_back(w);
        }
        return res;
        
    }
};