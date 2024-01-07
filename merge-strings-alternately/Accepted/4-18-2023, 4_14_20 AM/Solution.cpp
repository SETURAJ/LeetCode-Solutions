// https://leetcode.com/problems/merge-strings-alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int left=0,right=0;
        int n=word1.size(),m=word2.size();
        string ans;
        while(left<n && right<m)
        {
            ans+=word1[left++];
            ans+=word2[right++];
        }
        ans+=word1.substr(left);
        ans+=word2.substr(right);
        return ans;
    }
};