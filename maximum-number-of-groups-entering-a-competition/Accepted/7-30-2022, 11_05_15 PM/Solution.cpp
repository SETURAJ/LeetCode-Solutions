// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int count=0;
        int n=grades.size();
        if(n==2)
            return 1;
        sort(grades.begin(),grades.end());
        int z=1;
        while(n)
        {
            if(n<z)
                break;
            n-=z;
            z+=1;
            count++;
        }
        return count;
    }
};