// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    
    bool validpal(string &s,int low,int high,int count)
    {
        if(count>1)
            return false;
        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }
            else
            {
                return validpal(s,low+1,high,count+1) || validpal(s,low,high-1,count+1);
            }
            
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int low=0,high=s.size()-1;
        return validpal(s,low,high,0);
    }
};