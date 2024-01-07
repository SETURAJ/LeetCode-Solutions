// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int low=1,high=n,mid;
        while(low<=high)
        {
            long long int mid=(low+high)/2;
            if(!isBadVersion(mid))
                low=mid+1;
            else if(mid==1 || !isBadVersion(mid-1))
                return mid;
            else 
                high=mid-1;
        }
        return low;
    }
};