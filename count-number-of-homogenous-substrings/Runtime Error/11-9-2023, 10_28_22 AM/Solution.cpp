// https://leetcode.com/problems/count-number-of-homogenous-substrings

class Solution {
public:
    int countHomogenous(string s) {
        int res = 0;
        int mod = 1000000007;
        if(s.length()==0)
            return res;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            int cnt = 1;
            while(i<n-1 && s[i+1]==c)
            {
                cnt++;
                i++;
            }
            if(cnt==1)
                res += 1;
            else if(cnt==2)
                res += 3;
            else
            {
                res+=(cnt)%mod;
                res+=(((cnt)%mod*((cnt-1)%mod))/2)%mod;
            }
        }
        return res%mod;
    }
};