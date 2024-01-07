// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>uset;
        if(s.length()<k)
            return false;
        int left=0;
        int n=s.length();
        while(n-left>=k)
        {
            string a=s.substr(left,2);
            uset.insert(a);
            left++;
        }
        int ans=pow(2,k);
        //if(uset.size()==ans)
          //  return true;
        //return false;
        return uset.size()==ans;
    }
};