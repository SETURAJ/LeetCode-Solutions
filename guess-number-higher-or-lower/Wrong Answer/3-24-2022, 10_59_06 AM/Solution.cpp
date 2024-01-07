// https://leetcode.com/problems/guess-number-higher-or-lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int high=n, low=1;
        while(low<high)
        {
            long long int mid=(low+high)/2;
            int res=guess(mid);
            if(res==0)
                return mid;
            else if(res==-1)
                high=mid-1;
            else
                low=mid+1;
            
        }
        return 0;
    }
};