// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int left=0,right=n-1,mid;
        while(left<=right)
        {
            mid= (left+right)/2;
            if(letters[mid]<=target)
                left=mid+1;
            else
                right=mid-1;
        }
        return left == letters.size() ? letters[0]:letters[left];

    }
};