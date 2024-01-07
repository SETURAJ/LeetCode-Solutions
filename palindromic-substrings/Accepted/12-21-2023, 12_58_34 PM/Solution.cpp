// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    
    int ispal(string s,int left, int right)
    {
        //cout<<s<<endl;
        while(left<=right)
        {
           if(s[left]!=s[right])
               return 0;
            left++;
            right--;
        }
        return 1;
    }
    
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                res += ispal(s,i,j);
            }
        }
        return res;
    }
};