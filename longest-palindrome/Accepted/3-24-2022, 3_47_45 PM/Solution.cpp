// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(128,0);
        for(int i=0;i<s.length();i++)
            count[s[i]]++;
        int ans=0;
        for(auto v:count){
            ans += v / 2 * 2;
            if (ans % 2 == 0 && v % 2 == 1)
                ans++;
        }
        return ans;
    }
};