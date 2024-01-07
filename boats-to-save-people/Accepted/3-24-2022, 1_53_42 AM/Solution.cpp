// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int right=people.size()-1;
        int left=0;
        int ans=0;
        while(left<=right)
        {
            if(people[right]+people[left]>limit)
            {
                right--;
                ans++;
            }   
            else
            {
                left++;
                right--;
                ans++;
            }
        }
        return ans;
    }
};